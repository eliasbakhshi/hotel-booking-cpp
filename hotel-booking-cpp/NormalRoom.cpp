#pragma once
#include "NormalRoom.h"

NormalRoom::NormalRoom(int id, int roomNum, int size, bool isAvailable)
	:Room(id, roomNum, size, isAvailable)
{
}

NormalRoom::NormalRoom() {
}

void NormalRoom::enterMinibarContent() {
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

string NormalRoom::getRoomInfo() {
    return to_string(this->getId()) + ") Type: Normal, Number: " + to_string(this->getNumber()) + ", Size: " + to_string(this->getSize()) + "sqm";
    //string minibarString = "";
	//for (int i = 0; i < 3; i++) {
	//	minibarString += minibar[i] + " ";
	//}
	//return "The number of this normal room is: " + to_string(getRoomNum()) +
	//	"The size of the room is: " + to_string(getRoomSize()) + 
	//	"The items in the minibar are: " + minibarString;
}
