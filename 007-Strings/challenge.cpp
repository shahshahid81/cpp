/*
A simple and very old method of sending secret messages is the substitution cipher.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{

  string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  string message{};
  cout << "Enter message: ";
  getline(cin, message);

  size_t n{message.length()};

  string encrypted{};
  for (size_t i = 0; i < n; i++)
  {
    size_t index = alphabet.find(message.at(i));

    if (index == string::npos)
    {
      encrypted += message.at(i);
    }
    else
    {
      encrypted += key.at(index);
    }
  }
  cout << "Encrypted Message: " << encrypted << endl;

  string decrypted{};
  for (size_t i = 0; i < n; i++)
  {
    size_t index = key.find(encrypted.at(i));

    if (index == string::npos)
    {
      decrypted += encrypted.at(i);
    }
    else
    {
      decrypted += alphabet.at(index);
    }
  }
  cout << "Decrypted Message: " << decrypted << endl;

  return 0;
}
