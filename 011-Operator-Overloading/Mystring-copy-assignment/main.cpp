#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring a{"Hello"};  // overloaded constructor
    Mystring b;           // no-args contructor
    b = a;                // copy assignment
                          // b.operator=(a)
    b = "This is a test"; // b.operator=("This is a test");

    Mystring empty;          // no-args constructor
    Mystring larry("Larry"); // overloaded constructor
    Mystring stooge{larry};  // copy constructor
    Mystring stooges;        // no-args constructor

    empty = stooge; // copy assignment operator

    empty.display(); 
    larry.display(); 
    stooge.display();
    empty.display(); 

    stooges = "Larry, Moe, and Curly";
    stooges.display();

    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");

    cout << "=== Loop 1 ==================" << endl;
    for (const Mystring &s : stooges_vec)
    {
        s.display();
    }

    cout << "=== Loop 2 ==================" << endl;
    for (Mystring &s : stooges_vec)
    {
        s = "Changed"; // copy assignment
    }

    cout << "=== Loop 3 ================" << endl;
    for (const Mystring &s : stooges_vec)
    {
        s.display();
    }
    return 0;
}
