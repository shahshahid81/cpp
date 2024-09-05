#include <iostream>

using namespace std;

class Base
{
public:
  virtual void say_hello() const
  {
    std::cout << "Hello - I'm a Base class object" << std::endl;
  }
};

// Using final keyword with class ensures that class not be extended
class Derived final : public Base
{
public:
  // Using final keyword with method ensures that method cannot be overriden
  virtual void say_hello() const override final
  {
    std::cout << "Hello - I'm a Derived class object" << std::endl;
  }
};

// Error cannot override final class
// class Another : public Derived
// {
// public:
//   virtual void say_hello() const override
//   { // Error cannot override final method
//     std::cout << "Hello - I'm a Another class object" << std::endl;
//   }
// };

void greetings(const Base &obj)
{
  std::cout << "Greetings: ";
  obj.say_hello();
}

using namespace std;

int main()
{
  Base b;
  b.say_hello();

  Derived d;
  d.say_hello();

  Base *p1 = new Base();
  p1->say_hello();

  Derived *p2 = new Derived();
  p2->say_hello();

  Base *p3 = new Derived();
  p3->say_hello();

  std::cout << "\n========================" << std::endl;
  greetings(b);
  greetings(d);
  greetings(*p1);
  greetings(*p2);
  greetings(*p3);
  return 0;
}
