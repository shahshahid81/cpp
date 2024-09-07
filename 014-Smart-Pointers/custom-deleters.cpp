#include <iostream>
#include <memory>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// ptr passed here is the pointer that is internally used by the shared_ptr object
// We can use this to properly release the memory that cannot be released by c++ delete
// For eg, if we are using some c structure or malloc, then we can call free within this method which won't be handled automatically by the shared_ptr
void my_deleter(Test *ptr) {
    std::cout << "\tUsing my custom function deleter" << std::endl;
    delete ptr;
}

int main() {

    {
        // Using a function 
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter };
    }

    std::cout << "====================" << std::endl;
    {
        // Using a Lambda expression
        std::shared_ptr<Test> ptr2 (new Test{1000}, 
            [] (Test *ptr)  {
                std::cout << "\tUsing my custom lamdba deleter" << std::endl;
                delete ptr;
            });
    }
    
    return 0;
}