#include <iostream>
#include <memory>

using namespace std;

class B; // forward declaration

class A
{
    std::shared_ptr<B> b_ptr;

public:
    void set_B(std::shared_ptr<B> &b)
    {
        b_ptr = b;
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B
{

    // std::shared_ptr<A> a_ptr;     // uncomment this and comment weak_ptr to make the strong circular reference

    /**
     * Weak pointer points to an object of type T on the heap but does not owns it.
     * It is created from a shared pointer.
     * Memory allocation is handled by shared pointer itself
     */

    std::weak_ptr<A> a_ptr; // make weak to break the strong circular reference
public:
    void set_A(std::shared_ptr<A> &a)
    {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main()
{

    /**
        Here, we have made a strong circular reference by creating two pointers a and b.
        a has pointer to B on the heap which incremented the shared ptr b_ptr count by 1.
        b has pointer to A on the heap which incremented the shared ptr a_ptr count by 1.
        If both of them use shared ptr, since the reference for both is 1, a and b will go out of scope and will be deleted but the data on the heap won't be deleted.
        Using weak_ptr allows us to not have ownership of resource on heap and de allocate the memory.
    */

    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_B(b);
    b->set_A(a);

    return 0;
}
