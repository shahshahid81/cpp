#include <iostream>

using namespace std;

int *create_array(size_t size, int init_value = 0)
{
    // Important thing here is we are returning pointer which is pointing to heap instead of stack.
    // If we use stack here, the memory allocated will be free after the execution of the function which will result in error.
    // Heap Memory is used which will be preserved unless de allocated.
    int *new_storage{nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; ++i)
        *(new_storage + i) = init_value;
    return new_storage;
}

void display(const int *const array, size_t size)
{
    for (size_t i{0}; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    int *my_array{nullptr};
    size_t size;
    int init_value{};

    cout << "\nHow many integers would you like to allocate? ";
    cin >> size;
    cout << "What value would you like them initialized to? ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    cout << "\n--------------------------------------" << endl;

    display(my_array, size);
    delete[] my_array;
    return 0;
}