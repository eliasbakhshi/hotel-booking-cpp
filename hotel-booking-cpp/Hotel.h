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
	Hotel();
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
	int showHotels();
	void update(int id);
	void addNormalRoom(int id, int roomNum, int floor, int size);
	void addVipRoom(int id, int roomNum, int floor, int size);
	int showRooms();
	Room* getRoomByIndex(int index);
	int showOptions(int roomId);
	void addGuest(Guest guest);
	void registerGuest(Guest& guest);
	void showGuests() const;
	bool clearGuestVector();
	bool clearRoomVector();
	string bookingNumGenerator();

	void updateGuest(int id, string firstName, string lastName, string email, string phone, string password);
};