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
	string name, city, country, address;
	int hotelId = 0;
	vector<unique_ptr<Room>> rooms;
	vector<unique_ptr<Guest>> guests;

public:
	Hotel(string name, string city, string country);
	Hotel(int id);
	~Hotel();
	void setHotelId(int id);
	void setName(string name);
	void setCity(string city);
	void setCountry(string country);
	void setAddress(string address);
	int getHotelId();
	string getName();
	string getCity();
	string getCountry();
	string getAddress();
	vector<unique_ptr<Guest>> getGuests();
	void addGuest(Guest guest);
	void addNormalRoom(int id, int roomNum, int floor, int size);
	void addVipRoom(int id, int roomNum, int floor, int size);
	int showRooms();
	int showOptions(int roomId);
	void showGuests() const;
	bool removeGuest(int id);


};