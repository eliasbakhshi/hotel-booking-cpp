#pragma once
#include "Headers.h"

class Room {
private:
	int id,number, floor, size;
	bool isAvailable;
public:
	Room();
	Room(int id, int number, int size, bool isAvailable);
	virtual ~Room();
	void setId(int id);
	void setNumber(int number);
	void setFloor(int floor);
	void setIsAvailable(bool isAvailable);
	void setSize(int size);
	int getId();
	int getFloor();
	int getNumber();
	int getSize();
	bool getIsAvailable();

	virtual string getRoomInfo() = 0;
};
