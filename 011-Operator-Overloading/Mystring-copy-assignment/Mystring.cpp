#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    // Creating memory on heap
    str = new char[std::strlen(source.str) + 1];
    // Copying data from source
    std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring()
{
    delete[] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Copy assignment" << std::endl;
    // No need to do anything if the operator is called on itself
    // Example: Mystring str; str = str;
    if (this == &rhs)
        return *this;
    // deallocate the memory first before assigning new one.
    delete[] this->str;
    // create new memory on heap
    str = new char[std::strlen(rhs.str) + 1];
    // copy the data from source
    std::strcpy(this->str, rhs.str);
    return *this;
}

// Display method
void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }
