#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    cout << "Width: " << endl;

    // C-like initialization
    // int width = 0;

    // Constructor initialization
    // int width(0);

    // C++11 list initialization syntax, recommended approach
    int width{0};
    cin >> width;

    cout << "Height: " << endl;
    int height{0};
    cin >> height;

    cout << "Area: " << width * height << endl;

    return 0;
}
