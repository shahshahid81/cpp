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
}

Mystring::Mystring(Mystring &&source)
    : str(source.str)
{
    source.str = nullptr;
}

Mystring::~Mystring()
{
    delete[] str;
}

Mystring &Mystring::operator=(const Mystring &rhs)
{

    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs)
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &in, Mystring &rhs)
{
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete[] buff;
    return in;
}

// Here, we are not checking if this == rhs since it will be an infinite loop
// Also, this will be non null since it is calling the operator ==
// Also, rhs will be non null since it is a reference which cannot be null
bool Mystring::operator==(const Mystring &rhs) const
{
    // My Solution
    // if (this->get_length() != rhs.get_length())
    // {
    //     return false;
    // }
    // for (size_t i = 0; i < this->get_length(); i++)
    // {
    //     if (this->get_str()[i] != rhs.get_str()[i])
    //     {
    //         return false;
    //     }
    // }
    // return true;

    // Instructor Solution
    return std::strcmp(str, rhs.str) == 0;
}

bool Mystring::operator!=(const Mystring &rhs) const
{
    // My Solution
    // if (this->get_length() != rhs.get_length())
    // {
    //     return true;
    // }
    // for (size_t i = 0; i < this->get_length(); i++)
    // {
    //     if (this->get_str()[i] != rhs.get_str()[i])
    //     {
    //         return true;
    //     }
    // }
    // return false;

    // Instructor Solution
    return std::strcmp(str, rhs.str) != 0;
}

bool Mystring::operator>(const Mystring &rhs) const
{
    // My Solution
    // int m = this->get_length(), n = rhs.get_length();
    // int size = m >= n ? m : n;
    // for (int i = 0; i < size; i++)
    // {
    //     if (i >= m)
    //     {
    //         return false;
    //     }
    //     if (i >= n)
    //     {
    //         return true;
    //     }
    //     int diff = this->get_str()[i] - rhs.get_str()[i];
    //     if (diff == 0)
    //     {
    //         continue;
    //     }
    //     return diff > 0;
    // }
    // return false;

    // Instructor Solution
    return std::strcmp(str, rhs.str) > 0;

}

bool Mystring::operator<(const Mystring &rhs) const
{
    // My Solution
    // return this != &rhs && rhs > *this;

    // Instructor Solution
    return std::strcmp(str, rhs.str) < 0;
}

Mystring Mystring::operator-() const
{
    // My Solution

    // char *str = new char[this->get_length() + 1];
    // char *current = str;
    // for (size_t i = 0; i < this->get_length(); i++)
    // {
    //     *current = tolower(this->get_str()[i]);
    //     current++;
    // }
    // current[this->get_length()] = '\0';

    /*
    Returning the response this way is causing a memory leak.
    Since we are returning Mystring{str}, a new memory in heap will be allocated and contents of str will be copied to that location.
    After that, our str won't be used but since we didn't called delete, it will result in memory leak.
    Hence, we have below created a copy first, deleted the pointer, then returned the copy instead of directly returning the copy.
    */
    // return Mystring{str}; // Memory Leak 

    // Instructor Solution
    // Difference is this solution uses std methods to avoid null character handling
    // Also, member is directly used instead of getter
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < this->get_length(); i++)
    {
        buff[i] = std::tolower(this->get_str()[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
    // My Solution
    // char *str = new char[this->get_length() + rhs.get_length() + 1];
    // strcpy(str, this->get_str());
    // char *current = str + this->get_length();
    // for (size_t i = 0; i < rhs.get_length(); i++)
    // {
    //     *current = rhs.get_str()[i];
    //     current++;
    // }
    // current[this->get_length()] = '\0';
    // return Mystring{str}; // Memory Leak

    // Instructor Solution
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring& Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs;
    return *this;
}

Mystring Mystring::operator*(const int &rhs) const
{
    // My Solution
    // char *str = new char[this->get_length() * rhs + 1];
    // char *current = str;
    // for (size_t i = 0; i < rhs; i++)
    // {
    //     strcpy(current, this->get_str());
    //     current += this->get_length();
    // }
    // current[this->get_length()] = '\0';
    // return Mystring{str}; // Memory Leak

    // Instructor Solution
    Mystring temp;
    for(int i = 1; i <= rhs; i++) {
        temp = temp + *this;
    }
    return temp;
}

Mystring& Mystring::operator*=(const int &rhs)
{
    *this = *this * rhs;
    return *this;
}

// This is prefix operator since there is no param passed to us.
// We can directly modify the this value.
Mystring &Mystring::operator++()
{
    // My solution
    // const char *str = this->get_str();
    // char *copy = new char[this->get_length() + 1];
    // strcpy(copy, str);
    // char *current = copy;
    // for (size_t i = 0; i < this->get_length(); i++)
    // {
    //     *current = toupper(this->get_str()[i]);
    //     current++;
    // }
    // current[this->get_length()] = '\0';
    // *this = copy;
    // return *this;

    // Instructor Solution
    for(size_t i = 0; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// This is postfix operator since there is one int param which is a dummy param that helps identify post fix.
// We have to store the this value first, modify the this and return old so that it can be used.
Mystring Mystring::operator++(int value)
{
    // My Solution
    // char *copy = new char[this->get_length() + 1];
    // strcpy(copy, this->get_str());

    // char *modified_value = new char[this->get_length() + 1];
    // strcpy(modified_value, this->get_str());

    // char *current = modified_value;
    // for (size_t i = 0; i < this->get_length(); i++)
    // {
    //     *current = toupper(this->get_str()[i]);
    //     current++;
    // }
    // current[this->get_length()] = '\0';
    // *this = modified_value;
    // return copy;

    // Instructor Solution
    Mystring temp {*this};
    operator++();
    return temp;
}
