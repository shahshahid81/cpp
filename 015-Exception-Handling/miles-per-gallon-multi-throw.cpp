#include <iostream>
#include <string>

double calculate_mpg(int miles, int gallons)
{
  if (gallons == 0)
  {
    throw 0;
  }
  if (miles < 0 || gallons < 0)
  {
    throw std::string{"Negative value error"};
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
  // Multiple catch blocks, matching one will be executed
  catch (int &ex)
  {
    std::cerr << "Tried to divide by zero" << std::endl;
  }
  catch (std::string &ex)
  {
    std::cerr << ex << std::endl;
  }
  // We can use below statement to catch any kind of exception
  // catch(...) { }
  std::cout << "Bye" << std::endl;

  return 0;
}
