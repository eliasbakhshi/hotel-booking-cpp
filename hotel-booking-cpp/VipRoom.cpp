#pragma once
#include "VipRoom.h"

VipRoom::VipRoom(int roomNum, bool isAvailable)
	:Room(roomNum, isAvailable) 
{
}

VipRoom::VipRoom() {
	this->roomSize = 46;
	this->numOfMeals = 3;
}

VipRoom::~VipRoom() {
	delete[] this->meals;
}

void VipRoom::chooseRoomSize(int roomSize) {
	if (roomSize < 80) {
		this->roomSize = roomSize;
	}
	else {
		cout << "The max size of room is 80sqm!" << endl;
	}
}

void VipRoom::whatMeals(int numOfMeals) {
	this->numOfMeals = numOfMeals;
	if (numOfMeals == 1) {
		this->meals[0] = "Breakfast";
	}
	else if (numOfMeals == 2) {
		this->meals[0] = "Breakfast";
		this->meals[1] = "Lunch";
	}
	else if (numOfMeals == 3) {
		this->meals[0] = "Breakfast";
		this->meals[1] = "Lunch";
		this->meals[2] = "Dinner";
	}
	else {
		cout << "You can only choose a maximum number of 3 meals!" << endl;
	}
}

string VipRoom::printRoomInfo() {
	string mealsString = "";
	for (int i = 0; i < numOfMeals; i++) {
		mealsString += meals[i] + " ";
	}
	return "The number of this VIP room is: " + to_string(this->getRoomNum()) +
		"\nThe room size is: " + to_string(this->roomSize) + "sqm\n" + 
		"The meals included are: " + mealsString;
}


