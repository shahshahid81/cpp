#include <iostream>

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;`

int main()
{

    int *int_ptr{nullptr};
    int_ptr = new int;       // allocate the int on the heap. We an also use malloc for this, but new operator provides type safety and also do other operations like constructor calling etc.
    cout << int_ptr << endl; // use it
    delete int_ptr;          // release it

    size_t size{0};
    double *temp_ptr{nullptr};

    cout << "How many temps? ";
    cin >> size;

    temp_ptr = new double[size]; // allocate the storage on the heap
    cout << temp_ptr << endl;    // use it
    delete[] temp_ptr;           // release it. We can also use free for this, but delete operator performs other operations as well like destructor calling etc.

    cout << endl;
    return 0;
}
