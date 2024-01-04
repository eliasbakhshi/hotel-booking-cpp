#pragma once
#include "NormalRoom.h"

NormalRoom::NormalRoom(int id, int number, int floor, int size)
    :Room(id, number, floor, size, "normal"){}

NormalRoom::NormalRoom() {
}

void NormalRoom::showMinibarContent() {
    string whatsPresent[5]{ "Irish whiskey", "Festis hallon", "Peanuts", "Chips", "Absolut vodka" };
    cout << "Choose three items to include in your minibar:\n" << endl;

    try {
        for (int i = 0; i < 3; i++) {
            cout << "Item " << i + 1 << ": ";
            cin >> this->minibar[i];

            if (this->minibar[i] != whatsPresent[i]) {
                throw out_of_range("Item is not in stock!");
            }
        }
    }
    catch (out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// Prints out the room information(used in Hotel class)
string NormalRoom::getRoomInfo() {
    return to_string(this->getId()) + ") Type: Normal, Number: " + to_string(this->getNumber()) + " floor: " + to_string(this->getFloor()) + ", Size: " + to_string(this->getSize()) + "sqm";
}
