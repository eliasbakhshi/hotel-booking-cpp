#ifndef HOTEL_H
#define HOTEL_H
#include "Headers.h"
#include "Building.h"

class Hotel : public Building {
private:
	int stars, floor;
	string name, phone, roomNum;
public:
	Hotel();
	Hotel(int roomNr, int floor);
	~Hotel();

	int getId();
	void setId(int id);
	int getFloor();
	void setFloor(int floor);
	string getName();
	void setName(string name);
	string getPhone();
	void setPhone(string roomNr);
	string toString() override;
};



#endif