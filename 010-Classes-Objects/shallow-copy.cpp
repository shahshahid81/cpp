// Note: this program will crash
#include <iostream>

using namespace std;

class Shallow
{
private:
  int *data;

public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }
  // Constructor
  Shallow(int d);
  // Copy Constructor
  Shallow(const Shallow &source);
  // Destructor
  ~Shallow();
};

Shallow::Shallow(int d)
{
  data = new int;
  *data = d;
}

// Here, we are initalizing data to memobry address of source.data instead of copying value from source.data address into our own data pointer which is resulting in crash of the program due to freeing of same source twice in destructor resulting in error.
Shallow::Shallow(const Shallow &source)
    : data(source.data)
{
  cout << "Copy constructor  - shallow copy" << endl;
}

Shallow::~Shallow()
{
  delete data;
  cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s)
{
  cout << s.get_data_value() << endl;
}

int main()
{

  Shallow obj1{100};
  display_shallow(obj1);

  Shallow obj2{obj1};
  obj2.set_data_value(1000);

  return 0;
}
