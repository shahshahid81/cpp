#include <iostream>
#include <string>
#include <vector>

using namespace std; // Avoid using whole namespace, better practice is to either not use `using` or include only needed items like `using std::cout;`

class Player
{
    // Default is private.
public:
    string Name;

    int health{100};

    // Value will be garbage unless initialized.
    int xp;

    // Important to have semi-colon after class.
};

int main()
{
    Player player;
    Player *player_ptr = new Player;

    cout << player.health << endl; // Will Print 100
    cout << player.xp << endl;     // Will Print Garbage

    cout << player_ptr->health << endl; // Will Print 100
    cout << player_ptr->xp << endl;     // Will Print 0, because new will default initialize using default constructor

    int num1;
    int *num2 = new int;

    cout << num1 << endl;  // Will print garbage
    cout << *num2 << endl; // Will print 0

    return 0;
}
