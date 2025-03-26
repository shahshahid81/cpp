#include <iostream>

using std::cout;
using std::endl;

int main()
{

    enum Direction
    {
        left,
        right,
        up,
        down
    };

    Direction heading{left};

    switch (heading)
    {
    case left:
        cout << "Going left" << endl;
        break;
    case right:
        cout << "Going right" << endl;
        break;
    default:
        cout << "OK" << endl;
    }

    cout << endl;
    return 0;
}
