#ifndef HOTEL_H
#define HOTEL_H

#include "Headers.h"
#include "FileManager.h"
#include "ManageString.h"
#include "VipRoom.h"
#include "NormalRoom.h"

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

	void addVipRoom(VipRoom room);
	void addNormalRoom(NormalRoom room);
	void showRooms();


};

#endif