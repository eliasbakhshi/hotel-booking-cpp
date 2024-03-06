#include "NormalRoom.h"

ManageInputs miNormal;
ManageString msNormal;

NormalRoom::NormalRoom(int id, int number, int floor, int size)
	:Room(id, number, floor, size, "normal") {}

NormalRoom::NormalRoom() {}

string NormalRoom::getMinibarContent() {
	string optionNums, comma;
	int optionNum;

	while (true) {
		system("cls");
		if (chosenSnacks.size()) { // Show the list of selected option
			cout << "Your selected options: \n\n";
			for (int option : chosenSnacks) {
				cout << minibar[option - 1] << endl;
			}
			cout << endl << endl;
		}
		cout << "0) None" << ".\n";
		for (int i = 0; i < minibar.size(); i++) {
			cout << i + 1 << ") " << minibar[i] << ".\n";
		}
		cout << minibar.size() + 1 << ") Next step.\n";
		optionNum = miNormal.get_int("\n\nChoose the addon option for the room: ", 0, minibar.size() + 1);
		if ((optionNum != 0) && (optionNum <= minibar.size())) {
			if (find(begin(chosenSnacks), end(chosenSnacks), optionNum) == end(chosenSnacks)) {
				// save id of the selected option as string
				optionNums += comma + minibar[optionNum - 1];
				chosenSnacks.push_back(optionNum);
			}
			comma = ",";
		} else if (optionNum == minibar.size() + 1) {
			break;
		} else if (!optionNum) {
			optionNums = "";
			break;
		}
	}
	return optionNums;
}

void NormalRoom::showMinibarContent() {
	if (this->chosenSnacks.size() != 0) {
		cout << "--------------------" << endl;
		cout << "Meals included are: " << endl;
		for (int option : this->chosenSnacks) {
			cout << minibar[option - 1] << endl;
		}
		cout << "--------------------" << endl;
	}
}

// Prints out the room information(used in Hotel class)
string NormalRoom::getRoomInfo() {
	return to_string(this->getId()) + ") Type: Normal, Number: " + to_string(this->getNumber()) + " floor: " + to_string(this->getFloor()) + ", Size: " + to_string(this->getSize()) + "sqm";
}
