#include "VipRoom.h"

VipRoom::VipRoom(int roomNum, bool isAvailable)
	:Room(roomNum, isAvailable) 
{
}

VipRoom::VipRoom() {
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