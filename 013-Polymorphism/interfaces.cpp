#include <iostream>

// C++ doesn't have interface but we can make one by making all the methods as public pure virtual methods.
// It is convention to add 'I_' before class name to signify that this is an interface.
class I_Printable
{
  friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Printable() {}
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class Account : public I_Printable
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Account::withdraw" << std::endl;
  }
  virtual void print(std::ostream &os) const override
  {
    os << "Account display";
  }
  virtual ~Account() {}
};

class Checking : public Account
{
public:
  virtual void withdraw(double amount) override
  {
    std::cout << "In Checking::withdraw" << std::endl;
  }
  virtual void print(std::ostream &os) const override
  {
    os << "Checking display";
  }
  virtual ~Checking() {}
};

class Savings : public Account
{
public:
  virtual void withdraw(double amount) override
  {
    std::cout << "In Savings::withdraw" << std::endl;
  }
  virtual void print(std::ostream &os) const override
  {
    os << "Savings display";
  }
  virtual ~Savings() {}
};

class Trust : public Account
{
public:
  virtual void withdraw(double amount) override
  {
    std::cout << "In Trust::withdraw" << std::endl;
  }
  virtual void print(std::ostream &os) const override
  {
    os << "Trust display";
  }
  virtual ~Trust() {}
};

class Dog : public I_Printable
{
public:
  virtual void print(std::ostream &os) const override
  {
    os << "Woof woof";
  }
};

void print(const I_Printable &obj)
{
  std::cout << obj << std::endl;
}

int main()
{

  Dog *dog = new Dog();
  std::cout << *dog << std::endl;

  print(*dog);

  Account *p1 = new Account();
  std::cout << *p1 << std::endl;

  Account *p2 = new Checking();
  std::cout << *p2 << std::endl;

  // operator<< cannot be overloaded since it is function not a method and it cannot be virtual
  // Instead we have created a virtal print method where we can use the << operator
  //    Account a;
  //    std::cout << a<< std::endl;
  //
  //    Checking c;
  //    std::cout << c << std::endl;
  //
  //    Savings s;
  //    std::cout << s << std::endl;
  //
  //    Trust t;
  //    std::cout << t << std::endl;

  delete p1;
  delete p2;
  delete dog;
  return 0;
}
