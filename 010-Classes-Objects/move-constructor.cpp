#include <iostream>
#include <vector>

using namespace std;

class Move
{
private:
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
    // It doesn't creates a copy of the object, but moves it. This is done by changing the pointer of the source to current and nulling out the source pointer.
    // Optional and if not used, copy constructors will be used.
    // Note that we are using && instead of &. && is used for R value reference while & is used for l value reference.
    // Whenever && is used , you cannot assigned variables to it but literals can be assigned.
    Move(Move &&source);
    // Destructor
    ~Move();
};

Move::Move(int d)
{
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy ctor
Move::Move(const Move &source)
    : Move{*source.data}
{
    cout << "Copy constructor  - deep copy for: " << *data << endl;
}

// Move ctor
Move::Move(Move &&source)
    // Initalize the str of the current objetc with the pointer address stored in data from temp object. Here, only the memory address is copied instead of creating new memory on the heap and copying the content.
    : data{source.data}
{
    // Null out the data pointer of the temporary data effectively moving the data to the current object.
    // If we don't do this, then the data will be deleted by the destructor and it will affect the current object as well.
    source.data = nullptr;
    cout << "Move constructor - moving resource: " << *data << endl;
}

Move::~Move()
{
    if (data != nullptr)
    {
        cout << "Destructor freeing data for: " << *data << endl;
    }
    else
    {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main()
{
    vector<Move> vec;

    vec.push_back(Move{10});
    /**
    The above statement works by first creating temporary Move object which has pointer to int data and has value 10. 
    Let us assume the memory address of above value is 1000.
    Then instead of creating a copy of `Move{10}` and passing it to vector, we move the data.
    This is done by using the memory address of the `Move{10}`'s data which is 1000 and copy it to our pointer and we null out the pointer once copy is done.
    Refer body of move constructor
    */

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});

    return 0;
}
