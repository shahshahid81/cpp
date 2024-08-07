// https://youtu.be/6KNdGnUiRBM?si=mt7vWTsF8bKfoG-K
// https://en.cppreference.com/w/cpp/preprocessor
#include <iostream>

int main()
{
    // https://stackoverflow.com/questions/1422729/how-does-an-uninitiliazed-variable-get-a-garbage-value
    // Variable is uninitialized and will have a garbage value.
    int favorite_number;
    std::cout << "Enter a number between 1 and 100:" << std::endl;
    std::cin >> favorite_number;
    std::cout << "Amazing!! That is my favorite number too." << std::endl;
    std::cout << "Really!! " << favorite_number << " is my favorite number too." << std::endl;
    return 0;
}