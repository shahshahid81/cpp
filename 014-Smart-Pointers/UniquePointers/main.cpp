#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main()
{
    Test *t = new Test{1000};
    delete t;
    /*
        Unique ptr points to an object of type passed on the heap and is deallocated automatically, we don't need to handle the deallocation.
        Unique ptr cannot be assigned or copied.
    */
    std::unique_ptr<Test> t1{new Test{100}};
    // Using make_unique is the recommended approach. The parameters passed to make_unique are the ones that are passed to the constructor.
    // make_unique decides which constructor to call by using 

    // https://www.youtube.com/watch?v=F9fCmbyzBM0 -> remove_reference
    // Move implementation
    // template <class T>
    // typename remove_reference<T>::type&&
    // move(T&& a)
    // {
    //     return a;
    // }
    
    // Reference forwarding, use to call the constructor
    // https://www.youtube.com/watch?v=uVLm5OclfvQ
    // https://www.youtube.com/watch?v=c5dQX6GV_4g

    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

    std::unique_ptr<Test> t3;
    // Copying a unique pointer is not allowed. However, we can move the data.
    // std::move casts the value to an r value reference and if the LHS class have move constructor available, data is moved instead
    t3 = std::move(t1);
    if (!t1)
        std::cout << "t1 is nullptr" << std::endl;

    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    // Can be referenced like a normal pointer using * operator
    std::cout << *a1 << std::endl;
    // Can be referenceed like a normal pointer using -> operator
    a1->deposit(5000);
    // We can also use get method which returns the reference. We also have reset method which clears the current data and allows us to use the ptr to point to other object.
    std::cout << a1.get() << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Checking_Account>("James", 1000));
    accounts.push_back(make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(make_unique<Trust_Account>("Bobby", 5000, 4.5));

    for (const auto &acc : accounts)
        std::cout << *acc << std::endl;
    return 0;
}
