#pragma once
#include "NormalRoom.h"

ManageInputs miNormal;
ManageString msNormal;

NormalRoom::NormalRoom(int id, int number, int floor, int size)
	:Room(id, number, floor, size, "normal") {}

NormalRoom::NormalRoom() {}

string NormalRoom::getMinibarContent() {
	vector<int> selectedOptions;
	vector<string> options = { "Irish whiskey", "Festis hallon", "Peanuts", "Chips", "Absolut vodka" };
	string optionNums, comma;
	int optionNum;

	while (true) {
		system("cls");
		if (selectedOptions.size()) { // Show the list of selected option
			cout << "Your selected options: \n\n";
			for (int option : selectedOptions) {
				cout << options[option - 1] << endl;
			}
			cout << endl << endl;
		}
		cout << "0) None" << ".\n";
		for (int i = 0; i < options.size(); i++) {
			cout << i + 1 << ") " << options[i] << ".\n";
		}
		cout << options.size() + 1 << ") Next step.\n";
		optionNum = miNormal.get_int("\n\nChoose the addon option for the room: ", 0, options.size() + 1);
		if ((optionNum != 0) && (optionNum <= options.size())) {
			if (find(begin(selectedOptions), end(selectedOptions), optionNum) == end(selectedOptions)) {
				// save id of the selected option as string
				optionNums += comma + options[optionNum - 1];
				selectedOptions.push_back(optionNum);
			}
			comma = ",";
		} else if (optionNum == options.size() + 1) {
			break;
		} else if (!optionNum) {
			optionNums = "";
			break;
		}
	}
	return optionNums;
}

void NormalRoom::showMinibarContent() {
	cout << "Addons are: " << endl;

	for (int i = 0; i < 3; i++) {
		cout << this->minibar[i] << endl;
	}
}

// Prints out the room information(used in Hotel class)
string NormalRoom::getRoomInfo() {
	return to_string(this->getId()) + ") Type: Normal, Number: " + to_string(this->getNumber()) + " floor: " + to_string(this->getFloor()) + ", Size: " + to_string(this->getSize()) + "sqm";
}
