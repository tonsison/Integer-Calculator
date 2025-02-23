// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy

#include <iostream>
#include "header.h"
#include <sstream>

using namespace std;

IntSLList::~IntSLList()
{
  while (head != nullptr)
  {
    IntSLLNode *temp = head;
    head = head->next;
    delete temp;
  }
}

void IntSLList::addToHead(int el)
{
  head = new IntSLLNode(el, head);
  if (tail == nullptr)
  {
    tail = head;
  }
}

void IntSLList::addToTail(int el)
{
  if (tail != nullptr)
  {
    tail->next = new IntSLLNode(el);
    tail = tail->next;
  }
  else
  {
    head = tail = new IntSLLNode(el);
  }
}

int IntSLList::deleteFromHead()
{
  int el = head->info;
  IntSLLNode *tmp = head;
  if (head == tail)
  {
    head = tail = 0;
  }
  else
  {
    head = head->next;
  }
  delete tmp;
  return el;
}

int IntSLList::deleteFromTail()
{
  int el = tail->info;
  if (head == tail)
  {
    delete head;
    head = tail = 0;
  }
  else
  {
    IntSLLNode *tmp;
    for (tmp = head; tmp->next != tail; tmp = tmp->next)
      ;
    delete tail;
    tail = tmp;
    tail->next = 0;
  }
  return el;
}

void IntSLList::deleteNode(int el)
{
  if (head != 0)
  {
    if (head == tail && el == head->info)
    {
      delete head;
      head = tail = 0;
    }
    else if (el == head->info)
    {
      IntSLLNode *tmp = head;
      head = head->next;
      delete tmp;
    }
    else
    {
      IntSLLNode *pred, *tmp;
      for (pred = head, tmp = head->next;
           tmp != 0 && !(tmp->info == el);
           pred = pred->next, tmp = tmp->next)
        ;

      if (tmp != 0)
      {
        pred->next = tmp->next;
        if (tmp == tail)
        {
          tail = pred;
        }
        delete tmp;
      }
    }
  }
}

bool IntSLList::isInList(int el) const
{
  IntSLLNode *tmp;
  for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
  return tmp != 0;
}

bool IntSLList::isIdentical(const IntSLList &sll) const
{
  IntSLLNode *tmp = head;
  IntSLLNode *tmp2 = sll.head;

  while (tmp != nullptr && tmp2 != nullptr)
  {
    if (tmp->info != tmp2->info)
    {
      return false;
    }
    tmp = tmp->next;
    tmp2 = tmp2->next;
  }
  return tmp == nullptr && tmp2 == nullptr;
}

IntSLLNode *reverse(IntSLLNode *head)
{
  IntSLLNode *prev = nullptr, *curr = head, *next;

  while (curr != nullptr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

IntSLLNode *trimLeadingZeros(IntSLLNode *head)
{
  if (head == nullptr)
  {
    return nullptr; 
  }

  while (head->next != nullptr && head->info == 0)
  {
    head = head->next;
  }
  return head;
}

// Function to convert a string to a linked list
IntSLList IntSLList::stringToList(const string &num)
{
  IntSLList list;
  for (char digit : num)
  {
    if (isdigit(digit))
    {
      list.addToTail(digit - '0');
    }
  }
  return list;
}

IntSLLNode *addTwoLists(IntSLLNode *num1, IntSLLNode *num2)
{
  IntSLLNode *res = nullptr;
  IntSLLNode *curr = nullptr;
  int carry = 0;

  num1 = trimLeadingZeros(num1);
  num2 = trimLeadingZeros(num2);

  num1 = reverse(num1);
  num2 = reverse(num2);

  while (num1 != nullptr || num2 != nullptr || carry != 0)
  {
    int sum = carry;

    if (num1 != nullptr)
    {
      sum += num1->info;
      IntSLLNode *tmp = num1;
      num1 = num1->next;
    }

    if (num2 != nullptr)
    {
      sum += num2->info;
      IntSLLNode *tmp = num2;
      num2 = num2->next;
    }

    IntSLLNode *newNode = new IntSLLNode(sum % 10);

    carry = sum / 10;

    if (res == nullptr)
    {
      res = newNode;
      curr = newNode;
    }
    else
    {
      curr->next = newNode;
      curr = curr->next;
    }
  }

  return reverse(res);
}

// function for checking if string is an integer
bool isInteger(const string str)
{
  if (str.empty())
    return false; 

  size_t startIndex = 0;
  if (str[0] == '-')
  {
    startIndex = 1;
    if (str.length() == 1)
    {
      return false; // "-" is not a valid integer
    }
  }

  // Check if all remaining characters are digits
  for (size_t i = startIndex; i < str.length(); ++i)
  {
    if (!std::isdigit(str[i]))
    {
      return false; // Found a non-digit character
    }
  }
  return true;
}

bool inputVal(string &input, string &command, string &int1, string &int2)
{
  command = "";
  int1 = "";
  int2 = "";
  istringstream iss(input);

  iss >> command;
  if (command == "exit")
  {
    cout << "\nExiting program...";
    exit(1);
  }
  else if (command == "add" || command == "mult")
  {
    if (iss >> int1 && iss >> int2)
    {
      return isInteger(int1) && isInteger(int2);
    }
    else
    {
      cout << "\nInvalid input.\n";
      return false;
    }
  }
  else
  {
    cout << "\nInvalid input.\n";
    return false;
  }
}

// Function to print a linked list
void printList(IntSLLNode *head)
{
  while (head != nullptr)
  {
    cout << head->info;
    head = head->next;
  }
  cout << endl;
}

IntSLLNode *IntSLList::getHead() const
{
  return head;
}

IntSLLNode *multiplyTwoLists(IntSLLNode *num1, IntSLLNode *num2)
{
  if (num1 == nullptr || num2 == nullptr)
  {
    return new IntSLLNode(0); 
  }

  num1 = reverse(num1);
  num2 = reverse(num2);

  // Initialize the result as nullptr
  IntSLLNode *result = new IntSLLNode(0); 

  IntSLLNode *ptr2 = num2;
  int position = 0; 

  // Traverse through each digit of num2
  while (ptr2 != nullptr)
  {
    int carry = 0;
    // Stores the partial product
    IntSLLNode *tempResult = nullptr; 

    // Add leading zeros according to the position in the result
    for (int i = 0; i < position; ++i)
    {
      IntSLLNode *zeroNode = new IntSLLNode(0);
      zeroNode->next = tempResult;
      tempResult = zeroNode;
    }

    // Multiply num1 with current digit of num2
    IntSLLNode *ptr1 = num1;
    while (ptr1 != nullptr)
    {
      int product = (ptr1->info * ptr2->info) + carry;
      carry = product / 10;
      product = product % 10;

      IntSLLNode *newNode = new IntSLLNode(product);
      newNode->next = tempResult;
      tempResult = newNode;

      ptr1 = ptr1->next;
    }

    // If there is a remaining carry
    if (carry > 0)
    {
      IntSLLNode *carryNode = new IntSLLNode(carry);
      carryNode->next = tempResult;
      tempResult = carryNode;
    }

    // Add the partial result to the main result
    result = addTwoLists(result, tempResult);

    // Move to the next position
    ptr2 = ptr2->next;
    position++;
  }

  result = trimLeadingZeros(result);

  return result;
}
