#include <iostream>
#include <vector>

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;` 

int main()
{

  vector<int> vec{10, 20, 30, 40, 50};

  for (int item : vec)
  {
    cout << item << " ";
  }
  cout << endl;

  return 0;
}
