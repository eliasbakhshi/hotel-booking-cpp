#ifndef HOTEL_H
#define HOTEL_H
#include "Headers.h"

class Hotel {
private:
	int id;
	string name;
	string address;
	int stars;
	int roomNr;
	int floor;
public:
	Hotel();
	Hotel(int roomNr, int floor);
	virtual ~Hotel();
	int getRoom();
	void setRoom(int roomNr);

	virtual int getFloor() = 0;
	virtual void setFloor(int floor) = 0;
}; 

#endif