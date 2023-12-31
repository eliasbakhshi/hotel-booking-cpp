#pragma once
#include "NormalRoom.h"

NormalRoom::NormalRoom(int roomNum, bool isAvailable)
	:Room(roomNum, isAvailable)
{
}

NormalRoom::NormalRoom() {
}

int NormalRoom::getRoomSize() {
	return this->roomSize;
}

void NormalRoom::enterMinibarContent() {
    string whatsPresent[5]{ "Irish whiskey", "Festis hallon", "Peanuts", "Chips", "Absolut vodka" };
    cout << "Choose three items to include in your minibar:\nIrish whiskey, Festis hallon, Peanuts, Chips, and Absolut vodka\n" << endl;

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

string NormalRoom::printRoomInfo() {
	return string();
	//string minibarString = "";
	//for (int i = 0; i < 3; i++) {
	//	minibarString += minibar[i] + " ";
	//}
	//return "The number of this normal room is: " + to_string(getRoomNum()) +
	//	"The size of the room is: " + to_string(getRoomSize()) + 
	//	"The items in the minibar are: " + minibarString;
}
