#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main()
{

  Mystring larry{"Larry"};
  larry.display();

  larry = -larry;
  larry.display();

  cout << boolalpha << endl;
  Mystring moe{"Moe"};
  Mystring stooge = larry;

  cout << (larry == moe) << endl;
  cout << (larry == stooge) << endl;

  //  Mystring stooges = larry + "Moe";
  Mystring stooges = "Larry" + moe; // Now OK with non-member function. Conversion of Larry will happen from char * to Mystring object because of availability of the constructor that takes char * and return Mystring.
  stooges.display();                // LarryMoe

  Mystring two_stooges = moe + " " + "Larry";
  two_stooges.display(); // Moe Larry
  Mystring three_stooges = moe + " " + larry + " " + "Curly";
  three_stooges.display(); // Moe larry Curly

  return 0;
}
