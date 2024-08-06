#include <iostream>

int main()
{
    int favorite_number;
    std::cout << "Enter a number between 1 and 100:" << std::endl;
    std::cin >> favorite_number;
    std::cout << "Amazing!! That is my favorite number too." << std::endl;
    std::cout << "Really!! " << favorite_number << " is my favorite number too." << std::endl;
    return 0;
}