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

string VipRoom::showMeals() {
	// shows all the meals chosen by the VIP user
	string content = "";
	for (int i = 0; i < this->numOfMeals; i++) {
		content += this->meals[i] + " ";
	}
	return content;
}

void VipRoom::whatMeals(int numOfMeals) {
	// Lets the user choose what meals they want
	this->numOfMeals = numOfMeals;
	if (numOfMeals == 1) {
		meals[0] = "Breakfast";
	}
	else if(numOfMeals == 2) {
		meals[0] = "Breakfast";
		meals[1] = "Lunch";
	}
	else if (numOfMeals == 3) {
		meals[0] = "Breakfast";
		meals[1] = "Lunch";
		meals[2] = "Dinner";
	}
}


string VipRoom::getRoomInfo() {
	// Prints out the room information(used in Hotel class)
	return to_string(this->getId()) + ") Type: VIP, Number: " + to_string(this->getNumber()) + ", Size: " + to_string(this->getSize()) + "sqm";
	/*string mealsString = "";
	for (int i = 0; i < numOfMeals; i++) {
		mealsString += meals[i] + " ";
	}*/
			//", meals included are: " + mealsString + ".";
}


