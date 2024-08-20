#include <iostream>
#include <climits> 
// make sure you include climits for integer types
// Similar information for floating point numbers
// is contained in <cfloat>

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;` 

int main()
{

    // Variables will have different size on different machines based on whether the machine is 32 bit or 64 bit and there are implementation differences as well.

    // The only things guaranteed about types are:
    // sizeof(char) == 1
    // sizeof(char) <= sizeof(short)
    // sizeof(short) <= sizeof(int)
    // sizeof(int) <= sizeof(long)
    // sizeof(long) <= sizeof(long long)
    // sizeof(char) * CHAR_BIT >= 8
    // sizeof(short) * CHAR_BIT >= 16
    // sizeof(int) * CHAR_BIT >= 16
    // sizeof(long) * CHAR_BIT >= 32
    // sizeof(long long) * CHAR_BIT >= 64

    cout << "sizeof information" << endl;
    cout << "========================" << endl;

    cout << "char: " << sizeof(char) << " bytes." << endl;
    cout << "int : " << sizeof(int) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "short: " << sizeof(short) << " bytes." << endl;
    cout << "long: " << sizeof(long) << " bytes." << endl;
    cout << "long long: " << sizeof(long long) << " bytes." << endl;

    cout << "========================" << endl;

    cout << "float: " << sizeof(float) << " bytes." << endl;
    cout << "double: " << sizeof(double) << " bytes." << endl;
    cout << "long double: " << sizeof(long double) << " bytes." << endl;
    //
    //
    // use values defined in <climits>
    cout << "========================" << endl;

    cout << "Minimum values:" << endl;
    cout << "char: " << CHAR_MIN << endl;
    cout << "int: " << INT_MIN << endl;
    cout << "short: " << SHRT_MIN << endl;
    cout << "long: " << LONG_MIN << endl;
    cout << "long long: " << LLONG_MIN << endl;
    //
    cout << "========================" << endl;

    cout << "Maximum values:" << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "long: " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MAX << endl;
    //
    // sizeof can also be used with variable names
    cout << "========================" << endl;

    cout << "sizeof using variable names" << endl;
    int age{21};
    cout << "age is " << sizeof(age) << " bytes." << endl;
    // or
    cout << "age is " << sizeof age << " bytes." << endl;

    double wage{22.24};
    cout << "wage is " << sizeof(wage) << " bytes." << endl;
    // or
    cout << "wage is " << sizeof wage << " bytes." << endl;

    return 0;
}
