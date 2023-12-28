#ifndef HOTEL_H
#define HOTEL_H

#include "Headers.h"
#include "Room.h"

class Hotel {
private:
	string name, city, country;
	int nrOfRooms;
	vector<Room> rooms;

public:
	Hotel(string name, string city, string country);
	Hotel();
	~Hotel();
	void setName(string name);
	void setCity(string city);
	void setCountry(string country);
	string getName();
	string getCity();
	string getCountry();

	void addRoom(Room room);
	void showRooms();

};

#endif