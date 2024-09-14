#include <iostream>

int main()
{
  int miles{};
  int gallons{};
  double miles_per_gallon{};

  std::cout << "Enter the miles driven: ";
  std::cin >> miles;
  std::cout << "Enter the gallons used: ";
  std::cin >> gallons;

  try
  {
    if (gallons == 0)
    {
      // Here, we can throw any primitive or object that we want.
      throw 0;
    }
    miles_per_gallon = static_cast<double>(miles) / gallons;
    std::cout << "Result: " << miles_per_gallon << std::endl;
  }
  // Best practice is to catch the exception by reference always.
  // Catching by value makes a copy of the exception. But you don't rethrow the copy. You rethrow the original exception that was copied. As such, any modification to the exception caught by value will be lost, including the slicing.
  catch (int &ex)
  {
    std::cerr << "Sorry, you can't divide by zero" << std::endl;
  }
  std::cout << "Bye" << std::endl;
  return 0;
}
