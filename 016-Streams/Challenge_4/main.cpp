#include <iostream>
#include <fstream>

int main()
{
    std::ifstream poem{"romeoandjuliet.txt"};
    if (!poem)
    {
        std::cerr << "Error reading file" << std::endl;
        return 1;
    }

    int total_words{0};
    std::string line;
    while (std::getline(poem, line))
    {
        total_words++;
    }

    int line_number_digits = 0;
    do
    {
        total_words /= 10;
        line_number_digits++;
    } while (total_words != 0);

    poem.clear();
    poem.seekg(0, std::ios::beg);

    std::ofstream poem_output{"romeoandjulietline.txt"};
    if (!poem_output)
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int line_number{0};
    while (std::getline(poem, line))
    {
        poem_output << std::setw(line_number_digits) << std::left << (line_number++) << " " << line << std::endl;
    }

    poem.close();
    poem_output.close();
    return 0;
}
