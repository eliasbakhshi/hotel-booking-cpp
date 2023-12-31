#pragma once
#include "Headers.h"
#include "Room.h"

class VipRoom : public Room {
private:
	int numOfMeals;
	string* meals = new string[numOfMeals];
public:
	VipRoom(int id, int number, int size, bool isAvailable = true);
	VipRoom();
	~VipRoom();
	void chooseSize(int size);
	void whatMeals(int numOfMeals);

	string getRoomInfo() override;
};

