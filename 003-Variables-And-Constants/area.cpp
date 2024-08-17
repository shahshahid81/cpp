#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    cout << "Width: " << endl;

    // C-like initialization, called copy initialization
    // In this method, the value is initialized and assigned to a temporary variable and then copied to the current variable.
    // This is less efficent than other methods.
    // int width = 0;

    // Constructor initialization
    // Here, the value is directly initialized to the variable unlike creating and initializing value in temporary variable and then copying it to the variable.
    // This method can invoke constructors.
    // If no data passed in parantheses, default value will be used.
    // int width(0);

    // C++11 list initialization syntax, recommended approach
    // Here, the value is directly initialized to the variable unlike creating and initializing value in temporary variable and then copying it to the variable.
    // Also prevents implicit type conversion.
    // If no data passed in braces, default value will be used.
    int width{0};
    cin >> width;

    cout << "Height: " << endl;
    int height{0};
    cin >> height;

    cout << "Area: " << width * height << endl;

    return 0;
}
