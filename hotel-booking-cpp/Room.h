#pragma once
#include "Headers.h"

class Room {
private:
	int roomNum;
	int floor;
	bool isAvailable;
public:
	Room();
	Room(int roomNum, bool isAvailable);
	virtual ~Room();
	void setRoomNum(int roomNum);
	void setFloor(int floor);
	void setIsAvailable(bool isAvailable);
	int getFloor();
	int getRoomNum();
	bool getIsAvailable();

	virtual string printRoomInfo() = 0;
};
