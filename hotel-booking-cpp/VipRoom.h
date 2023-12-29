#ifndef VIPROOM_H
#define VIPROOM_H

#include "Room.h"
#include "Headers.h"

class VipRoom : public Room {
private:
	int roomSize;
	int numOfMeals = 3;
	string* meals = new string[numOfMeals];
public:
	VipRoom(int roomNum, bool isAvailable = true);
	VipRoom();
	void chooseRoomSize(int roomSize);
	void whatMeals(int numOfMeals);
};


#endif