#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Score
{
    std::string name;
    int score;
};

int getScore(const std::string &answer, const std::string &student_answer)
{
    int score{0};
    for (int i = 0; i < answer.length(); i++)
    {
        if (answer.at(i) == student_answer.at(i))
        {
            score++;
        }
    }
    return score;
}

int main()
{
    std::ifstream in_file;
    in_file.open("responses.txt");
    if (!in_file)
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::string line{};
    if (!(in_file >> line))
    {
        std::cerr << "Missing answers." << std::endl;
        return 1;
    }

    std::string answers{line};
    std::vector<Score> scores;
    int total_score{0};
    while (in_file >> line)
    {

        std::string name{line};

        if (!(in_file >> line))
        {
            std::cerr << "Missing student answer." << std::endl;
            return 1;
        }

        if (line.length() != answers.length())
        {
            std::cerr << "Missing student answer." << std::endl;
            return 1;
        }
        int score{getScore(answers, line)};
        total_score += score;
        scores.push_back(Score{name, score});
    }

    std::cout << "Student" << std::setw(23) << std::right << "Score" << std::endl;
    std::cout << std::setw(30) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    for (const Score &item : scores)
    {
        int space = 29 - item.name.length();
        std::cout << item.name << std::setw(space) << std::setfill(' ') << "" << item.score << std::endl;
    }
    std::cout << std::setw(30) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    std::cout << "Average" << std::setw(20) << std::setfill(' ') << "" << std::setprecision(1) << std::fixed << static_cast<double>(total_score) / scores.size() << std::endl;

    in_file.close();
    return 0;
}
