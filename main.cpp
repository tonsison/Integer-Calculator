// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy

#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
  string command, int1, int2;
  string userInput;

  do
  {
    cout << "Please enter your command: (ex. add [integer1] [integer2])";
    getline(cin, userInput);
  } while (!inputVal(userInput, command, int1, int2));

  if (command == "add")
  {
    IntSLList num1 = IntSLList::stringToList(int1);
    IntSLList num2 = IntSLList::stringToList(int2);
    IntSLLNode *result = addTwoLists(num1.getHead(), num2.getHead());
    cout << "Result: ";
    printList(result);
  } // exception error at this line when destructor operator is called
  else if (command == "mult")
  {
    // Implement multiplication logic here
  }

  return 0;
}
