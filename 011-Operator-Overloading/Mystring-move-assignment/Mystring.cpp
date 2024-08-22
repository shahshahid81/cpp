#include <iostream>
#include <cstring>
#include "Mystring.h"

Mystring::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

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
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
}

Mystring::Mystring(Mystring &&source)
    // Copying memory address of source to our own (Moving the data)
    : str(source.str)
{
    // Nulling out the source after Copying the memory address
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

Mystring::~Mystring()
{
    if (str == nullptr)
    {
        std::cout << "Calling destructor for Mystring : nullptr" << std::endl;
    }
    else
    {
        std::cout << "Calling destructor for Mystring : " << str << std::endl;
    }
    delete[] str;
}

Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    // Delete the string data pointed by the str pointer of current object
    delete[] str;
    // Copy the pointer address stored in str from temp object to current object. Here, only the memory address is copied instead of creating new memory on the heap and copying the content.
    str = rhs.str;
    // Null out the str pointer of the temporary data effectively moving the data to the current object.
    // If we don't do this, then the data will be deleted by the destructor and it will affect the current object as well.
    rhs.str = nullptr;
    return *this;
}

void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }
