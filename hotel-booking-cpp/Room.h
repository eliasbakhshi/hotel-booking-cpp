#pragma once
#include "Headers.h"

class Room {
private:
	int id = 0, number = 0, floor = 0, size = 0;
	string type;
public:
	Room();
	Room(int id, int number, int floor, int size, string type);
	virtual ~Room();
	void setId(int id);
	void setNumber(int number);
	void setFloor(int floor);
	void setSize(int size);
	void setType(string type);
	int getId();
	int getFloor();
	int getNumber();
	int getSize();
	string getType();

	virtual string getRoomInfo() = 0;
};
