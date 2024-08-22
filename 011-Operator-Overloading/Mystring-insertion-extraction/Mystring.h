#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    // Here, we are making operator friend of the class.
    // Here, we ensure to return the reference back, since operator can be chained.
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    // Here, we are making operator the method of the class. 
    // The method can access the private members and we don't need to pass the object on which the operator was called. We can access the current object by referring to this pointer.
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif