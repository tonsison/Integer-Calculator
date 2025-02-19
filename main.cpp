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
  LargeInt li1;
  LargeInt li2;
  LargeInt sum;
  LargeInt product;
  string userInput;

  do
  {
    cout << "Please enter your command: (ex. add [integer1] [integer2])";
    getline(cin, userInput);
  } while (!inputVal(userInput, command, int1, int2));

  // set LargeInt object
  li1.setLargeInt(int1);
  li2.setLargeInt(int2);

  if (command == "add")
  {
    sum = li1 + li2;
  }
  else if (command == "mult")
  {
  }
}