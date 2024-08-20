#include <iostream>

using namespace std;

class Deep
{
private:
  int *data;

public:
  void set_data_value(int d) { *data = d; }
  int get_data_value() { return *data; }
  // Constructor
  Deep(int d);
  // Copy Constructor
  Deep(const Deep &source);
  // Destructor
  ~Deep();
};

Deep::Deep(int d)
{
  data = new int;
  *data = d;
}

// Here, we are sending int data to default constructor which will create a new int variable on heap and assign it to pointer.s
// We are not copying the memory address of the pointer but creating a different memory area on heap and assign the value of the pointer passed. This will ensure that we have separate copies of same data.
Deep::Deep(const Deep &source)
    : Deep{*source.data}
{
  cout << "Copy constructor  - deep copy" << endl;
}

Deep::~Deep()
{
  delete data;
  cout << "Destructor freeing data" << endl;
}

void display_deep(Deep s)
{
  cout << s.get_data_value() << endl;
}

int main()
{

  Deep obj1{100};
  display_deep(obj1);

  Deep obj2{obj1};

  obj2.set_data_value(1000);

  return 0;
}
