#pragma once
#include "Headers.h"
#include "Room.h"
#include "ManageString.h"


class VipRoom : public Room {
private:
	string meals[3];
public:
	VipRoom(int id, int number, int floor, int size);
	VipRoom();
	string getMeals();
	void showMeals();

	string getRoomInfo() override;
};