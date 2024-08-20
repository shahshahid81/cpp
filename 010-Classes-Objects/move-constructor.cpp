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
    // It doesn't creates a copy of the object, but moves it. This is done by copying data from source and null out the source.
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
    : data{source.data}
{
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

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});

    return 0;
}
