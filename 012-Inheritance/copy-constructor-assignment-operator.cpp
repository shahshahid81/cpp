#include <iostream>

using namespace std;

class Base
{
private:
    int value;

public:
    Base()
        : value{0}
    {
        cout << "Base no-args constructor" << endl;
    }
    Base(int x)
        : value{x}
    {
        cout << "int Base constructor" << endl;
    }
    Base(const Base &other)
        : value{other.value}
    {
        cout << "Base copy constructor" << endl;
    }

    Base &operator=(const Base &rhs)
    {
        cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }

    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base
{
private:
    int doubled_value;

public:
    Derived() : Base{}
    {
        cout << "Derived no-args constructor " << endl;
    }
    Derived(int x)
        : Base{x}, doubled_value{x * 2}
    {
        cout << "int Derived constructor" << endl;
    }

    // Constructors, Destructors, overloaded operators and friend functions are not inherited.
    // For example, if base class has one int value and one default constructor and one int arg constructor and derived has another int value and no args constructor, then calling int arg constructor on derived will throw error instead of using the base class int constructor since it is not inherited.

    // Compiler will generate one default derived class copy / move constructor if not explicitly specified
    // Compiler will also call the base class constructor and then do member wise copy for derived members
    // However, if we have any pointers, compiler will do member wise copy and assign the same address of original pointer to the derived pointer. Instead, we should create a new memory area in heap and copy the value to the new address so that both original and copy have separate memory address and values.

    //  If we are generating our own derived class copy / move constructor, compiler won't call the base constructor and we would need to call the constructor explicitly if we need to use it.

    Derived(const Derived &other)
        : Base(other), doubled_value{other.doubled_value}
    {
        cout << "Derived copy / move constructor" << endl;
    }

    // Compiler will generate one default derived class operator= method if not explicitly specified
    // Compiler will also call the base class operator= and then do member wise copy for derived members
    // However, if we have any pointers, compiler will do member wise copy and assign the same address of original pointer to the derived pointer. Instead, we should create a new memory area in heap and copy the value to the new address so that both original and copy have separate memory address and values.

    //  If we are generating our own derived class operator= method, compiler won't call the base class operator= and we would need to call the operator= explicitly if we need to use it.
    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived operator=" << endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }
    ~Derived() { cout << "Derived destructor " << endl; }
};

int main()
{
    // Base b{100}; // Overloaded constructor
    // Base b1{b};  // Copy constructor
    // b = b1;      //   Copy assignment

    Derived d{100}; // Overloaded constructor
    Derived d1{d};  // Copy constructor
    d = d1;         // Copy assignment

    return 0;
}
