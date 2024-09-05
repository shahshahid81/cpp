#include <iostream>
#include <vector>

class Account
{
public:
  // Declaring a method as virtual will tell the compiler to not bound the method at run time and instead check the type of object the pointer is holding instead of type of pointer declared.
  // If we don't use virtual keyword then even if we have derived class objects, method of the base class will be called.
  // Refer basic-polymorphism for more details.
  // Derived classes don't need to use virtual keyword since the base has already marked method as virtual but it is best practice to be explicit
  // https://youtu.be/FncNE2vdtwQ
  virtual void withdraw(double amount)
  {
    std::cout << "In Account::withdraw" << std::endl;
  }

  // If a method is declared as virtaul, destructor must be declared as virtual too so that proper destructor is called at run time. Else behaviour is undefined if desctructor is not virtual.
  virtual ~Account() {}
};

class Checking : public Account
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Checking::withdraw" << std::endl;
  }

  virtual ~Checking() {}
};

class Savings : public Account
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Savings::withdraw" << std::endl;
  }
  virtual ~Savings() {}
};

class Trust : public Account
{
public:
  virtual void withdraw(double amount)
  {
    std::cout << "In Trust::withdraw" << std::endl;
  }
  virtual ~Trust() {}
};

int main()
{
  std::cout << "\n === Pointers ==== " << std::endl;
  Account *p1 = new Account();
  Account *p2 = new Savings();
  Account *p3 = new Checking();
  Account *p4 = new Trust();

  p1->withdraw(1000);
  p2->withdraw(1000);
  p3->withdraw(1000);
  p4->withdraw(1000);

  std::cout << "\n === Array ==== " << std::endl;
  Account *array[] = {p1, p2, p3, p4};
  for (auto i = 0; i < 4; ++i)
    array[i]->withdraw(1000);

  std::cout << "\n === Array ==== " << std::endl;
  array[0] = p4;
  for (auto i = 0; i < 4; ++i)
    array[i]->withdraw(1000);

  std::cout << "\n === Vector ==== " << std::endl;
  std::vector<Account *> accounts{p1, p2, p3, p4};
  for (auto acc_ptr : accounts)
    acc_ptr->withdraw(1000);

  std::cout << "\n === Vector ==== " << std::endl;
  accounts.push_back(p4);
  accounts.push_back(p4);
  for (auto acc_ptr : accounts)
    acc_ptr->withdraw(1000);

  std::cout << "\n === Clean up ==== " << std::endl;
  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return 0;
}
