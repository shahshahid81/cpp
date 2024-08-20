using std::endl;
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

int main(int argc, char const *argv[])
{
    // vector <char> vowels; // empty
    // vector <char> vowels (5); // Size of 5, initialized to zero
    vector<char> vowels{'a', 'i', 'e', 'o', 'u'};

    cout << vowels[0] << endl; // using index directly, bounds will not be checked
    cout << vowels[4] << endl;

    // vector<int> test_scores(3); // 3 elements, all initialized to zero
    // vector<int> test_scores(3, 100); // 3 elements, all initialized to 100
    vector<int> test_scores{100, 98, 80};

    cout << "\nTest scores using array syntax:" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\nTest scores using vector syntax:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "Size: " << test_scores.size() << endl;

    cout << "Enter 3 scores" << endl;
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);

    cout << "Updated Test scores:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "Size: " << test_scores.size() << endl;

    int new_score;
    cout << "Enter one more score:" << endl;
    cin >> new_score;
    test_scores.push_back(new_score);
    test_scores.at(0) = 99;

    cout << "Updated Test scores:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << "Size: " << test_scores.size() << endl;

    vector<vector<int>> matrix{{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    for (int i = 0; i < 3; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 4; j++)
        {
            cout << " " << matrix.at(i).at(j);
        }
        cout << endl;
    }

    vector<int> vector1, vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    vector2.push_back(100);
    vector2.push_back(200);

    vector<vector<int>> vector_2d;
    // Since we are passing value, copy will be created
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    for (int i = 0; i < vector_2d.size(); i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < vector_2d.at(i).size(); j++)
        {
            cout << " " << vector_2d.at(i).at(j);
        }
        cout << endl;
    }

    // Updating value at vector1 does not reflect in vector_2d because a copy was created in push_back
    // CPP uses pass by value unless reference is explicitly used. Whereas in java, reference is used.
    vector1.at(0) = 1000;

    for (int i = 0; i < vector_2d.size(); i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < vector_2d.at(i).size(); j++)
        {
            cout << " " << vector_2d.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}
