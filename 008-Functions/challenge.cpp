/*
Your program should display a menu options to the user as follows:

P - Print numbers
A - Add a number
M - Display mean of the numbers
S - Display the smallest number
L - Display the largest number
Q - Quit

Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.

If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void get_user_choice(char &option)
{
  cout << "\nP - Print numbers" << endl;
  cout << "A - Add a number" << endl;
  cout << "M - Display mean of the numbers" << endl;
  cout << "S - Display the smallest number" << endl;
  cout << "L - Display the largest number" << endl;
  cout << "Q - Quit" << endl;

  cout << "Enter your choice: ";
  cin >> option;
  option = toupper(option);
}

void print(const vector<int> &vec)
{
  cout << "[ ";
  for (int item : vec)
  {
    cout << item << " ";
  }
  cout << "]" << endl;
}

void add(vector<int> &vec)
{
  int num{};
  cout << "Number: ";
  cin >> num;
  vec.push_back(num);
}

void print_mean(const vector<int> &vec)
{
  if (vec.size() == 0)
  {
    cout << "No items in the list" << endl;
    return;
  }

  int sum{};
  for (int item : vec)
  {
    sum += item;
  }
  cout << "Mean: " << static_cast<double>(sum) / vec.size() << endl;
}

void print_smallest(const vector<int> &vec)
{

  if (vec.size() == 0)
  {
    cout << "No items in the list" << endl;
    return;
  }

  int smallest{vec.at(0)};
  for (int item : vec)
  {
    if (item < smallest)
    {
      smallest = item;
    }
  }
  cout << "Smallest: " << smallest << endl;
}

void print_largest(const vector<int> &vec)
{

  if (vec.size() == 0)
  {
    cout << "No items in the list" << endl;
    return;
  }

  int largest{vec.at(0)};
  for (int item : vec)
  {
    if (item > largest)
    {
      largest = item;
    }
  }
  cout << "Largest: " << largest << endl;
}

int main()
{

  vector<int> vec{};
  char option{};
  do
  {
    get_user_choice(option);

    if (option == 'Q')
    {
      cout << "Exiting Program..." << endl;
      return 0;
    }
    else if (option == 'P')
    {
      print(vec);
    }
    else if (option == 'A')
    {
      add(vec);
    }
    else if (option == 'M')
    {
      print_mean(vec);
    }
    else if (option == 'S')
    {
      print_smallest(vec);
    }
    else if (option == 'L')
    {
      print_largest(vec);
    }
    else
    {
      cout << "Invalid choice. Try again.";
    }
  } while (option != 'q' || option != 'Q');

  return 0;
}
