#include <iostream>
#include <string>
#include <vector>

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;`

int main()
{

    int num{100};
    int &ref{num};

    cout << num << endl;
    cout << ref << endl;

    num = 200;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;

    ref = 300;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;

    cout << "\n---------------------------------" << endl;
    vector<string> stooges{"Larry", "Moe", "Curly"};

    for (auto str : stooges)
        str = "Funny"; // str is a COPY of the each vector element

    for (auto str : stooges) // No change
        cout << str << endl;

    cout << "\n---------------------------------" << endl;
    for (auto &str : stooges) // str is a reference to each vector element
        str = "Funny";

    for (auto const &str : stooges) // notice we are using const
        cout << str << endl;        // now the vector elements have changed

    cout << endl;
    return 0;
}
