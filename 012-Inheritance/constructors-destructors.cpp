#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << "Base no-args constructor" << endl; }
    Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
    // Constructors are not inherited by default. Using below statement, we are inheriting constructors of the base class except some special constructors like copy, move etc. There are rules that are following for explicit inheritance of non special constructors.

    // If our derived class args constructor was commented, then without this statement, compiler will throw an error.
    // However, after using this, compiler won't throw an error and it will call base class args constructor.
    // However, base will only initialize it's own data and derived class data won't be initalized.
    // To understand better, run the program by commenting the args constructor for derived and then comment the below statement once and check and then check again by uncommenting below statement.
    using Base::Base; 

private:
    int doubled_value;

public:
    Derived() : doubled_value{0} { cout << "Derived no-args constructor " << endl; }
    Derived(int x) : doubled_value{x * 2} { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor " << endl; }
};

int main()
{
    // Base class no args constructor will be called
    // Constructors are called from base to derived but desctructors are called from derived to base.
    //   Base b;

    // Base class args constructor will be called
    //    Base b{100};

    // Derived class no-args constructor will be called and before that base class no-args constructor will be called
    // Derived d;
    // Output
    // Base no-args constructor
    // Derived no-args constructor 
    // Derived destructor 
    // Base destructor

    // Derived class args constructor will be called and before that base class no-args constructor will be called
    Derived d{1000};
    // Output
    // Base no-args constructor
    // Derived (int) overloaded constructor
    // Derived destructor 
    // Base destructor

    return 0;
}