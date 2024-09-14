#include <iostream>

double calculate_mpg(int miles, int gallons)
{
  if (gallons == 0)
  {
    // Here, we are throwing from the function so that the parent handler can handle the exception.
    // Compiler doesn't force the calling method to handle exception.
    // It will go up the call stack looking for handler and if not found, program will crash.
    throw 0;
  }
  return static_cast<double>(miles) / gallons;
}

int main()
{
  int miles{};
  int gallons{};
  double miles_per_gallon{};

  std::cout << "Enter the miles: ";
  std::cin >> miles;
  std::cout << "Enter the gallons: ";
  std::cin >> gallons;
  try
  {
    miles_per_gallon = calculate_mpg(miles, gallons);
    std::cout << "Result: " << miles_per_gallon << std::endl;
  }
  catch (int &ex)
  {
    std::cerr << "Tried to divide by zero" << std::endl;
  }
  std::cout << "Bye" << std::endl;

  return 0;
}
