// Section 8 Challenge
/*
  For this program I will be using US dollars and cents.

  Write a program that asks the user to enter the following:
  An integer representing the number of cents

  You may assume that the number of cents entered is greater than or equal to zero

  The program should then display how to provide that change to the user.

  In the US:
    1 dollar is 100 cents
    1 quarter is 25 cents
    1 dime is 10 cents
    1 nickel is 5 cents, and
    1 penny is 1 cent.

  Here is a sample run:

  Enter an amount in cents :  92

  You can provide this change as follows:
  dollars    : 0
  quarters : 3
  dimes     : 1
  nickels   : 1
  pennies  : 2
*/
#include <iostream>

using namespace std;

int main()
{

  const int dollar{100};
  const int quarter{25};
  const int dime{10};
  const int nickel{5};
  const int penny{1};

  cout << "Enter an amount in cents : ";
  int amount{0};
  cin >> amount;

  cout << "Dollars: " << amount / dollar << endl;
  amount %= dollar;

  cout << "Quarters: " << amount / quarter << endl;
  amount %= quarter;

  cout << "Dimes: " << amount / dime << endl;
  amount %= dime;

  cout << "Nickels: " << amount / nickel << endl;
  amount %= nickel;

  cout << "Pennies: " << amount << endl;

  return 0;
}
