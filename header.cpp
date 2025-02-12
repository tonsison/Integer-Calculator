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
  for (IntSLLNode *p; head != nullptr;)
  {
    p = head->next;
    delete head;
    head = p;
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
    for (tmp = head; tmp->next != tail; tmp = tmp->next);
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
  for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next)
    ;
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


LargeInt &LargeInt::operator=(const LargeInt &li)
{

}


LargeInt LargeInt::operator+(const LargeInt &li) const
{

}

LargeInt LargeInt::operator*(const LargeInt &li) const
{

}

LargeInt LargeInt::setLargeInt(const string &largeint)
{
  IntSLList sll;
  for(char c : largeint)
  {
    sll.addToHead(c - '0'); // subtracting '0' converts char to int
  }
}

// function for checking if string is an integer
bool isInteger(const string str)
{
  size_t startIndex = 0;
  if (str[0] == '-')
  {
    // A negative sign is allowed, but it should be only at the beginning
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
  else 
    if(command == "add" || command == "mult")
    {
      if(iss >> int1 && iss >> int2)
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