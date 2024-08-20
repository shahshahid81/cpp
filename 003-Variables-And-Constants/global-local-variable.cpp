#include <iostream>

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;` 

int age{18};

int main()
{

  int age{16};

  cout << age << endl;

  return 0;
}
