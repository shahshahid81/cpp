#include <iostream>
#include <string>
#include <vector>

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;`

void display(const vector<string> *const v)
{
    // Below statement is not allowed because of the second const, which doesn't allow modification of the pointed value
    // (*v).at(0) = "Funny";
    for (auto str : *v)
        cout << str << " ";
    cout << endl;

    // Below statement is not allowed because of the first const, which doesn't allow modification of the pointer value
    // v = nullptr;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *array, int sentinel)
{
    while (*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
}

void double_data(int *int_ptr)
{
    *int_ptr *= 2;
}

int main()
{
    int value{10};
    int *int_ptr{nullptr};

    cout << "Value: " << value << endl;
    double_data(&value);
    cout << "Value: " << value << endl;

    cout << "-----------------------------" << endl;
    int_ptr = &value;
    double_data(int_ptr);
    cout << "Value: " << value << endl;

    cout << endl;

    int x{100}, y{200};
    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;

    swap(&x, &y);

    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;

    cout << "-----------------------------" << endl;
    vector<string> stooges{"Larry", "Moe", "Curly"};
    display(&stooges);

    cout << "\n-----------------------------" << endl;
    int scores[]{100, 98, 97, 79, 85, -1};
    display(scores, -1);

    return 0;
}
