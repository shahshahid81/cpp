#include <iostream>

void func_a();
void func_b();
void func_c();

void func_a()
{
  std::cout << "Starting func_a" << std::endl;
  func_b();
  std::cout << "Ending func_a" << std::endl;
}

void func_b()
{
  std::cout << "Starting func_b" << std::endl;
  try
  {
    func_c();
  }
  // Here, we have catched the exception in func_b so it will be executed properly till the end. However, if we had caught the exception in func_a, then execution of func_b would have stopped and execution would work properly from func_a
  catch (int &ex)
  {
    std::cout << "Caught error in func_b" << std::endl;
  }
  std::cout << "Ending func_b" << std::endl;
}

void func_c()
{
  std::cout << "Starting func_c" << std::endl;
  throw 100;
  std::cout << "Ending func_c" << std::endl;
}

int main()
{

  std::cout << "Starting main" << std::endl;
  try
  {
    func_a();
  }
  catch (int &ex)
  {
    std::cout << "Caught error in main" << std::endl;
  }
  std::cout << "Finishing main" << std::endl;
  return 0;
}
