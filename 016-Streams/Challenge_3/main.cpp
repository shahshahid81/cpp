#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    std::ifstream in_file;
    in_file.open("romeoandjuliet.txt");
    if (!in_file)
    {
        std::cerr << "File not found" << std::endl;
    }

    int total_words{0}, found_words{0};
    std::string search_term{""};

    std::cout << "Enter the substring to search for: ";
    std::cin >> search_term;

    std::string line{""};
    while (in_file >> line)
    {
        total_words++;
        if (line.find(search_term) != string::npos)
        {
            found_words++;
        }
    }

    std::cout << total_words << " words were searched..." << std::endl;
    std::cout << "The substring " << search_term << " was found " << found_words << " times" << std::endl;

    in_file.close();
    return 0;
}
