#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"

/*
We have 3 types of inheritance. public, private and protected. default is private.

Public Inheritance:
a. Private members of Base class are not accessible in Derived class.
b. Protected members of Base class remain protected in Derived class.
c. Public members of Base class remain public in Derived class.
So, other classes can use public members of Base class through Derived class object.

Protected Inheritance:
a. Private members of Base class are not accessible in Derived class.
b. Protected members of Base class remain protected in Derived class.
c. Public members of Base class too become protected members of Derived class.
So, other classes can't use public members of Base class through Derived class object; but they are available to subclass of Derived.

Private Inheritance:
a. Private members of Base class are not accessible in Derived class.
b. Protected & public members of Base class become private members of Derived class.
So, no members of Base class can be accessed by other classes through Derived class object as they are private in Derived class. So, even subclass of Derived class can't access them.

*/
class Savings_Account: public Account
{
public:
    double int_rate;
    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);
    void withdraw(double amount);
};

#endif // _SAVINGS_ACCOUNT_H_
