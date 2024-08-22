#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    // Here, the operator function are specified as the friends of the class.
    // This is done so that private members of the class can be accessed.
    // However, it is not necessary to do so.
    // Also, we need to pass the lhs as well since the operator is not a method.
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif
