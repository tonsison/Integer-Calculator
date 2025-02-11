// Authors
// Johann Audric Ferolino
// Jose Antonio Sison
// Carl Washington Siy

#include <iostream>

using namespace std;

class Node
{

};

class LargeInt
{
private:
public:
  LargeInt &operator=(const LargeInt &li);
  LargeInt operator+(const LargeInt &li) const;
  LargeInt operator*(const LargeInt &li) const;
  // LargeInt setLargeInteger(const);
};