#include <iostream>

// int min(int a, int b) {
//     return (a < b) ? a : b;
// }
//
// char min(char a, char b) {
//     return (a < b) ? a :  b;
// }
//
// double min(double a, double b) {
//     return (a < b) ? a : b;
// }

/*
  Instead of defining different functions for different types, macro is defined.
  Note that we are using parantheses for every element, this is a best practice since macros doesn't do any type checking or evalutaionan and is simple c++ substitution.

  For example,
  #define square(a) a * a

  int main() {
    cout << 100 / square(2); // instead of evaluating as 100 / 4 = 25, this will evaluate to 100 / 2 * 2 = 100 since code will be substituted to 100 / 2 * 2 which should be 100 / (2*2). Hence, it is best practice to use parantheses in macros.
  }

*/
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define max(a, b) ((a > b) ? a : b)
int main()
{

  std::cout << min(2, 3) << std::endl;
  std::cout << min('A', 'B') << std::endl;
  std::cout << min(12.5, 9.2) << std::endl;
  std::cout << min(5 + 2 * 2, 7 + 40) << std::endl;

  std::cout << max(10, 20) << std::endl;
  return 0;
}
