#include <iostream>
#include <memory>

class Base
{
public:
  void say_hello() const
  {
    std::cout << "Hello - I'm a Base class object" << std::endl;
  }
};

class Derived : public Base
{
public:
  void say_hello() const
  {
    std::cout << "Hello - I'm a Derived class object" << std::endl;
  }
};

// Here, since we are using base, even for derived class object, say_hello of base will be called since compiler doesnt check the type of data stored by the pointer but the type of pointer declared and link the method to be called at compile time to be more efficient.
void greetings(const Base &obj)
{
  std::cout << "Greetings: ";
  obj.say_hello();
}

int main()
{
  Base b;
  b.say_hello();

  Derived d;
  d.say_hello();

  greetings(b);
  greetings(d);

  Base *ptr = new Derived();
  ptr->say_hello();

  std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
  ptr1->say_hello();

  delete ptr;

  return 0;
}
