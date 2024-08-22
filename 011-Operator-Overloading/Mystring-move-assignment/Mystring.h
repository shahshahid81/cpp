#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    /**
        Here, we have both copy and move assignment operator.
        Appropriate operator will be used based on the type of the value (L Value Ref or R Value Ref)
    */
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif
