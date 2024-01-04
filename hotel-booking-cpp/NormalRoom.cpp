#pragma once
#include "NormalRoom.h"

NormalRoom::NormalRoom(int id, int number, int floor, int size)
    :Room(id, number, floor, size, "normal"){}

NormalRoom::NormalRoom() {
}

void NormalRoom::addMinibarContent() {
    int itemsChosen = 0;
    string whatsPresent[5]{ "Irish whiskey", "Festis hallon", "Peanuts", "Chips", "Absolut vodka" };
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ") " << whatsPresent[i] << "\n";
    }
    while (itemsChosen < 3) {
        int itemNum = 0;
        cout << "\nChoose three items to include in your minibar. Item " + to_string(itemsChosen + 1) + ": "; cin >> itemNum;
        this->minibar[itemsChosen] = whatsPresent[itemNum - 1];
        itemsChosen++;
    }
}

void NormalRoom::showMinibarContent() {
    for (int i = 0; i < 3; i++) {
        cout << this->minibar[i] << endl;
    }
}

// Prints out the room information(used in Hotel class)
string NormalRoom::getRoomInfo() {
    return to_string(this->getId()) + ") Type: Normal, Number: " + to_string(this->getNumber()) + " floor: " + to_string(this->getFloor()) + ", Size: " + to_string(this->getSize()) + "sqm";
}
