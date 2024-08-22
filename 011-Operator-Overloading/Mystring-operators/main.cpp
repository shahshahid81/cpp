#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    cout << boolalpha << endl;

    Mystring larry{"Larry"};
    Mystring moe{"Moe"};

    Mystring stooge = larry;
    larry.display();
    moe.display();

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    larry.display();
    Mystring larry2 = -larry;
    larry2.display();

    Mystring stooges = larry + "Moe"; // ok with member function
    // Mystring stooges = "Larry" + moe; // Compiler error. LHS should be a class object since methods are called on it.

    Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();
    // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " + "Curly";
    three_stooges.display(); //  Moe Larry Curly

    return 0;
}
