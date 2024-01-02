#pragma once
#include "Headers.h"
#include "Room.h"

class VipRoom : public Room {
private:
	int numOfMeals;
	string meals[3];
public:
	VipRoom(int id, int number, int size, bool isAvailable = true);
	VipRoom();
	~VipRoom();
	void whatMeals(int numOfMeals);
	string showMeals();

	string getRoomInfo() override;
};

