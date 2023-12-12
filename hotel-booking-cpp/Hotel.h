#ifndef HOTEL_H
#define HOTEL_H
#include "Headers.h"

class Hotel {
private:
	int id;
	string name;
	string address;
	int stars;
	int number;
	int floor;
public:
	Hotel();
	Hotel(int roomNr, int floor);
	virtual ~Hotel();

	int getId();
	void setId(int id);
	int getNumber();
	void setNumber(int roomNr);

	virtual int getFloor() = 0;
	virtual void setFloor(int floor) = 0;
}; 

#endif