#include <iostream>

// https://stackoverflow.com/questions/1452721/whats-the-problem-with-using-namespace-std
using namespace std;

int main()
{
    int first, second;
    cout << "Enter First: " << endl;
    cin >> first;
    cout << "Enter Second: " << endl;
    cin >> second;
    cout << "First: " << first << " Second: " << second << endl;

    /*
    Enter First: 1
    Enter Second: 2
    First: 1 Second: 2
    */

    int n;
    float f;

    cout << "Enter int: " << endl;
    cin >> n;
    cout << "Enter float: " << endl;
    cin >> f;
    cout << "Float: " << f << " Int: " << n << endl;

    /*
    Enter int:
    1
    Enter float:
    1.2
    Float: 1.2 Int: 1

    Here, since we added both numbers together, cin will keep reading from buffer until it can fit the data in first variable, output it and since data for second variable is already present, it will simply output it instead of waiting for input.
    Enter int:
    1 1.2
    Enter float:
    Float: 1.2 Int: 1

    Here, cin read 1 and sent it to int variable since the rest of the data is not valid. Then cin started reading next char which is .5 and stored it in float.
    Enter int:
    1.5
    Enter float:
    Float: 0.5 Int: 1

    Since the input is invalid, cin went to fail mode.
    https://stackoverflow.com/questions/69140185/behavior-of-stdcin-on-failure
    Enter First:
    a
    Enter Second: 
    First: 0 Second: 1819242352
    Enter int: 
    Enter float: 
    Float: 4.59135e-41 Int: 2063061936
    */

    return 0;
}
