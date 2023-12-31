#pragma once
#include "Headers.h"
#include "FileManager.h"
#include "ManageString.h"
#include "VipRoom.h"
#include "NormalRoom.h"
#include "Guest.h"

class Hotel {
private:
	string name, city, country;
	int nrOfRooms;
	vector<Room*> rooms;
	//Guest* guest;

public:
	Hotel(string name, string city, string country);
	Hotel();
	~Hotel();
	void setName(string name);
	void setCity(string city);
	void setCountry(string country);
	//void setGuest(Guest* guest);
	string getName();
	string getCity();
	string getCountry();
	//Guest *getGuest();

	void addRoom(Room* room);
	void showRooms();


};