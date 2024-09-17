#include <iostream>
#include <fstream>

int main() {
    /**
     * ifstream is only for reading from file.
     * fstream is for reading and writing both.
     * ofstream is for writing to file.
     */
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    
    in_file.open("test.txt");
    // operator bool() const 
    // there is an overload for types using the above method that is why we are able to use instance directly in if statement. We can convert from one type to another if we provide the conversion.
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    // Always close file to avoid memory leak
    in_file.close();
    return 0;
}

