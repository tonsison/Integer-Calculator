// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy


#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

#include <iostream>

using namespace std;


class IntSLLNode
{
  public:
    int info;
    IntSLLNode *next;
    IntSLLNode()
    {
      next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = nullptr)
    {
      info = el;
      next = ptr;
    }
};

IntSLLNode* addTwoLists(IntSLLNode* num1, IntSLLNode* num2);

class IntSLList 
{
  public:
    IntSLList() 
    {
      head = tail = nullptr;
    }
    ~IntSLList();
    int isEmpty()
    {
      return head == nullptr;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead(); // delete the head and return its info;
    int deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    bool isIdentical(const IntSLList &sll) const;
    static IntSLList stringToList(const string& num);
    IntSLLNode *getHead() const;

    
  private:
    IntSLLNode *head, *tail;
};


bool isInteger(const string str);
bool inputVal(string &input, string &command, string &int1, string &int2);
#endif


void printList(IntSLLNode* head);
