#pragma once
#include "VipRoom.h"

VipRoom::VipRoom(int id, int number, int size, bool isAvailable)
	:Room(id, number, size, isAvailable) 
{
}

VipRoom::VipRoom() {
	this->setSize(46);
	this->numOfMeals = 3;
}

VipRoom::~VipRoom() {
	delete[] this->meals;
}

void VipRoom::chooseSize(int size) {
	try {
		if (size < 80) {
			this->setSize(size);
		}
		else {
			throw out_of_range("The max size of the room is 80 sqm!");
		}
	}
	catch (out_of_range& exc) {
		cerr << "Error: " << exc.what() << endl;
	}
}

void VipRoom::whatMeals(int numOfMeals) {
	try {
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
			throw out_of_range("You can only choose a maximum number of 3 meals!");
		}
	}
	catch (out_of_range& exc) {
		cerr << "Error: " << exc.what() << endl;
	}
}


string VipRoom::getRoomInfo() {
	return to_string(this->getId()) + ") Type: VIP, Number: " + to_string(this->getNumber()) + ", Size: " + to_string(this->getSize()) + "sqm";
	/*string mealsString = "";
	for (int i = 0; i < numOfMeals; i++) {
		mealsString += meals[i] + " ";
	}*/
			//", meals included are: " + mealsString + ".";
}


