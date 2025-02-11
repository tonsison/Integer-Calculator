// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy

#include <iostream>
#include "header.h"

using namespace std;

// Create Addition Function (add)

// Create Multiplication Function (mult)

int main()
{
  LargeInt li1;
  LargeInt li2;
  LargeInt sum;
  LargeInt product;
  string userInput;

  cout << "Please enter your command: (ex. add [integer1] [integer2])";
  cin >> userInput;

  if (userInput == "exit")
  {
    return 0;
  }
  else 
    if(userInput == "add")
    {
      sum = li1 + li2;
    }
    else 
      if(userInput == "mult")
      {

      }
}