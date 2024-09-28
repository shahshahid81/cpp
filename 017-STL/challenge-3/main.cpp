#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
              << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair : words)
        std::cout << std::setw(12) << std::left << pair.first
                  << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
              << "Occurrences" << std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair : words)
    {
        std::cout << std::setw(12) << std::left << pair.first
                  << std::left << "[ ";
        for (auto i : pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in
// a string and returns the clean version
std::string clean_string(const std::string &s)
{
    std::string result;
    for (char c : s)
    {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the
// number of times they occur in the file

void part1()
{
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file{"words.txt"};
    if (in_file)
    {
        while (std::getline(in_file, line))
        {
            std::stringstream sstream{line};
            while (sstream >> word)
            {
                word = clean_string(word);
                // auto it = words.find(word);
                // if (it != words.end())
                // {
                //     it->second++;
                // }
                // else
                // {
                //     words.insert(std::make_pair(word, 1));
                // }
                words[word]++;
            }
        }

        in_file.close();
        display_words(words);
    }
    else
    {
        std::cerr << "Error opening input file" << std::endl;
    }
}

// Part2 process the file and builds a map of words and a
// set of line numbers in which the word appears
void part2()
{
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    int line_number{0};
    std::ifstream in_file{"words.txt"};
    if (in_file)
    {
        while (std::getline(in_file, line))
        {
            line_number++;
            std::stringstream sstream{line};
            while (sstream >> word)
            {
                word = clean_string(word);
                // auto it = words.find(word);
                // if (it != words.end())
                // {
                //     it->second.insert(line_number);
                // }
                // else
                // {
                //     words.insert(std::make_pair(word, std::set{line_number}));
                // }
                words[word].insert(line_number);
            }
        }

        in_file.close();
        display_words(words);
    }
    else
    {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main()
{
    part1();
    part2();
    return 0;
}
