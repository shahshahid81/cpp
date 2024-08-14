/**
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

If the user enters the string "ABC", then your program should display:

  A
 ABA
ABCBA


If the user enters the string, "12345", then your program should display:



    1
   121
  12321
 1234321
123454321


If the user enters 'ABCDEFG', then your program should display:



      A
     ABA
    ABCBA
   ABCDCBA
  ABCDEDCBA
 ABCDEFEDCBA
ABCDEFGFEDCBA

If the user enters 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', then your program should display:

                         A
                        ABA
                       ABCBA
                      ABCDCBA
                     ABCDEDCBA
                    ABCDEFEDCBA
                   ABCDEFGFEDCBA
                  ABCDEFGHGFEDCBA
                 ABCDEFGHIHGFEDCBA
                ABCDEFGHIJIHGFEDCBA
               ABCDEFGHIJKJIHGFEDCBA
              ABCDEFGHIJKLKJIHGFEDCBA
             ABCDEFGHIJKLMLKJIHGFEDCBA
            ABCDEFGHIJKLMNMLKJIHGFEDCBA
           ABCDEFGHIJKLMNONMLKJIHGFEDCBA
          ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
         ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
        ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
       ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
      ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
     ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
    ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
   ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
  ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
 ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA

If the user enters "C++isFun!", then your program should display:



        C
       C+C
      C+++C
     C++i++C
    C++isi++C
   C++isFsi++C
  C++isFuFsi++C
 C++isFunuFsi++C
C++isFun!nuFsi++C
*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

  cout << "Enter string: ";
  string str;
  cin >> str;

  int n = str.length();
  for(int i = 0; i < n; i++) {
    // Add space to the left, which is largest index in string - current index
    for(int j = n - 1 - i; j > 0; j--) cout << " "; 
    
    // Start printing characters from starting index till current index
    for(int j = 0; j <= i; j++) cout << str[j]; 
    
    // Start printing characters from current index - 1 till the starting index
    for(int j = i-1; j >= 0; j--) cout << str[j]; 
    
    // Add space to the right, which is largest index in string - current index
    for(int j = n - 1 - i; j > 0; j--) cout << " "; 
    
    cout << endl;
  }

  return 0;
}
