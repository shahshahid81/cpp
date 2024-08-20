#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

#include "Other_class.h"
class Friend_class;

/**
 Using friend keyword, we can allow access to private members of our class to other methods of a class or the whole class.

 Friendship has to be granted explicitly for it to work.

 If A is a friend of B, then B is not a freind of A.

 If A is a friend of B and B is a friend of C, then A is not a friend of C.
 */

class Player
{
    // Granting friendship to Other Class's display_player method
    friend void Other_class::display_player(Player &p);
    // Granting friendship to a function.
    friend void display_player(Player &p);
    // Granting friendship to Friend Class.
    friend class Friend_class;

private:
    static int num_players;
    std::string name;
    int health;
    int xp;

public:
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() { return xp; }
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player();

    static int get_num_players();
};

#endif // _PLAYER_H_
