#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char vowels[]{'a', 'e', 'i', 'o', 'u'}; // auto size detection
    cout << "\nThe first vowel is " << vowels[0] << endl;
    cout << "The last vowel is " << vowels[4] << endl;

    // Array bounds are not checked, ensure to use correct index
    // cin >> vowels[5];
    // cout << "Out of Bounds " << vowels[5] << endl;

    // Output:
    // The first vowel is a
    // The last vowel is u
    // 1
    // Out of Bounds 1
    // *** stack smashing detected ***: terminated
    // [1]    6761 IOT instruction (core dumped)  /home/shahid-shah/Projects/programming-languages/build/arrays

    double hi_temps[]{98.1, 89.8, 77.5, 81.6};
    cout << "The first high temperature is: " << hi_temps[0] << endl;
    hi_temps[0] = 100.7;
    cout << "The first high temperature is: " << hi_temps[0] << endl;

    // Arrays need to be initialized, same as variables or it will contain garbage values.
    int test_scores_uninitialized[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Score at index " << i << ": " << test_scores_uninitialized[i] << endl;
    }

    // Output:
    // Score at index 0: 1401034320
    // Score at index 1: 32767
    // Score at index 2: -1303717918
    // Score at index 3: 28999
    // Score at index 4: -1297641784

    // Using list initialization operator gives initial value. We can pass initial values. Rest will be zero. If nothing passed, all will be zero.
    int test_scores[5]{100};
    for (int i = 0; i < 5; i++)
    {
        cout << "Score at index " << i << ": " << test_scores[i] << endl;
    }
    // Output:
    // Score at index 0: 100
    // Score at index 1: 0
    // Score at index 2: 0
    // Score at index 3: 0
    // Score at index 4: 0

    for (int i = 0; i < 5; i++)
    {
        cout << "Score " << i << ": ";
        cin >> test_scores[i];
    }

    cout << "Updated Scores:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Score at index " << i << ": " << test_scores[i] << endl;
    }

    // Using array names print the address
    cout << "test_scores " << test_scores << endl;
    // Output:
    // test_scores 0x7ffc2870baf0

    int matrix[3][4]{{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    for (int i = 0; i < 3; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 4; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
