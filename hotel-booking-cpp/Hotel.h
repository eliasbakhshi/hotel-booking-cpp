#pragma once
#include "Headers.h"
#include "FileManager.h"
#include "ManageString.h"
#include "VipRoom.h"
#include "NormalRoom.h"
#include "Spa.h"
#include "Guest.h"

class Guest;

class Hotel {
private:
	string name, city, country;
	int nrOfRooms;
	//vector<Room*> rooms;
	//vector<Guest*> guests;
	vector<unique_ptr<Room>> rooms;
	vector<unique_ptr<Guest>> guests;

public:
	Hotel(string name, string city, string country);
	Hotel();
	~Hotel();
	void setName(string name);
	void setCity(string city);
	void setCountry(string country);
	void addGuest(Guest guest);
	string getName();
	string getCity();
	string getCountry();
	vector<unique_ptr<Guest>> getGuests();
	void addNormalRoom(int roomNum, int size, bool isAvailable);
	void addVipRoom(int roomNum, int size, bool isAvailable);
	void showRooms();
	void showGuests() const;
	bool removeGuest(int id);


};