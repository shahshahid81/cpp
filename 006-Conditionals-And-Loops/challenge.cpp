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

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;`

int main()
{

  vector<int> vec{};
  char option{};
  do
  {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;

    cout << "Enter your choice: ";
    cin >> option;

    if (option == 'q' || option == 'Q')
    {
      cout << "Exiting Program..." << endl;
      return 0;
    }
    else if (option == 'p' || option == 'P')
    {
      cout << "[ ";
      for (int item : vec)
      {
        cout << item << " ";
      }
      cout << "]" << endl;
    }
    else if (option == 'a' || option == 'A')
    {
      int num{};
      cout << "Number: ";
      cin >> num;
      vec.push_back(num);
    }
    else if (option == 'm' || option == 'M')
    {
      if (vec.size() == 0)
      {
        cout << "No items in the list" << endl;
        continue;
      }

      int sum{};
      for (int item : vec)
      {
        sum += item;
      }

      // static_cast is more safer than c style cast because there are some checks performed at compile time unlike c where there is no check.
      cout << "Mean: " << static_cast<double>(sum) / vec.size() << endl;
    }
    else if (option == 's' || option == 'S')
    {
      if (vec.size() == 0)
      {
        cout << "No items in the list" << endl;
        continue;
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
    else if (option == 'l' || option == 'L')
    {
      if (vec.size() == 0)
      {
        cout << "No items in the list" << endl;
        continue;
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
    else
    {
      cout << "Invalid choice. Try again.";
    }
  } while (option != 'q' || option != 'Q');

  return 0;
}
