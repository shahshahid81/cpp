#include <iostream>
#include <vector>

using namespace std;

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
