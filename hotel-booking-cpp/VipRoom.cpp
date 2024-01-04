#pragma once
#include "VipRoom.h"

VipRoom::VipRoom(int id, int number, int floor, int size)
	:Room(id, number, floor, size, "vip") {}

VipRoom::VipRoom() {
	this->setSize(46);
}

//string VipRoom::showMeals() {
//	// shows all the meals chosen by the VIP user
//	string content = "";
//	for (int i = 0; i < this->numOfMeals; i++) {
//		content += this->meals[i] + " ";
//	}
//	return content;
//}

void VipRoom::addMeals() {
	int itemsChosen = 0;
	string mealsPresent[3] = { "Breakfast", "Lunch", "Dinner" };
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ") " << mealsPresent[i] << "\n";
	}
	while (itemsChosen < 3) {
		int itemNum = 0;
		cout << "\nChoose three items to include in your minibar. Item " + to_string(itemsChosen + 1) + ": "; cin >> itemNum;
		this->meals[itemsChosen] = mealsPresent[itemNum - 1];
		itemsChosen++;
	}
}

void VipRoom::showMeals() {
	for (int i = 0; i < 3; i++) {
		cout << this->meals[i] << endl;
	}
}


// Prints out the room information(used in Hotel class)
string VipRoom::getRoomInfo() {
	return to_string(this->getId()) + ") Type: VIP, Number: " + to_string(this->getNumber()) + " floor: " + to_string(this->getFloor()) + ", Size: " + to_string(this->getSize()) + "sqm (Spa is included).";

}


