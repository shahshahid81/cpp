#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Small Rooms: " << endl;
    int small_rooms{0};
    cin >> small_rooms;

    cout << "Large Rooms: " << endl;
    int large_rooms{0};
    cin >> large_rooms;

    const int small_room_price = 25;
    const int large_room_price = 35;

    const int room_cost = (small_rooms * small_room_price) + (large_rooms * large_room_price);
    const float tax = 0.06;
    const float tax_cost = room_cost * tax;

    cout << "Cost: " << room_cost << endl;
    cout << "Tax: " << tax_cost << endl;
    cout << "Total: " << tax_cost + room_cost << endl;

    return 0;
}
