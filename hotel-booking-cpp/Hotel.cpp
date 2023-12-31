#pragma once
#include "Hotel.h"

FileManager fmHotel;
ManageString msHotel;

Hotel::Hotel(string name, string city, string country) {
	this->name = name;
	this->city = city;
	this->country = country;
}

Hotel::Hotel() {
	this->name = "";
	this->city = "";
	this->country = "";
}

Hotel::~Hotel() {
	for (Room* room : rooms) {
		delete room;
	}
}

void Hotel::setName(string name) {
	this->name = name;
}

void Hotel::setCity(string city) {
	this->city = city;
}

void Hotel::setCountry(string country) {
	this->country = country;
}

void Hotel::addGuest(Guest* guest) {
	this->guests.push_back(guest);
}

string Hotel::getName() {
	return this->name;
}

string Hotel::getCity() {
	return this->city;
}

string Hotel::getCountry() {
	return this->country;
}

vector<Guest*> Hotel::getGuests() {
	return this->guests;
}

void Hotel::addRoom(int number, int size, bool isAvailable) {
	fmHotel.setFilename("rooms.txt");
	int theId = fmHotel.getLastId() + 1;
	rooms.push_back(new NormalRoom(theId, number, size, isAvailable));
}


void Hotel::showRooms() {
	for (int i = 0; i < rooms.size(); i++) {
		cout << rooms[i]->getRoomInfo();
		/*NormalRoom* normalr = dynamic_cast<NormalRoom*>(&rooms[i]);
		VipRoom* vipr = dynamic_cast<VipRoom*>(&rooms[i]);
		Spa* spar = dynamic_cast<Spa*>(&rooms[i]);

		if (normalr) {
			string theAvailibility = to_string(rooms[i].getIsAvailable()) = "1" ? "available" : "is not available";
			cout << "The room number is: " + to_string(rooms[i].getRoomNum()) + " and the room is " + theAvailibility + ".\n";
		} else if(vipr){
			string theAvailibility = to_string(rooms[i].getIsAvailable()) = "1" ? "available" : "is not available";
			cout << "The room number is: " + to_string(rooms[i].getRoomNum()) + " and the room is " + theAvailibility + ".\n";
		} else if(spar){
			string theAvailibility = to_string(rooms[i].getIsAvailable()) = "1" ? "available" : "is not available";
			cout << "The room number is: " + to_string(rooms[i].getRoomNum()) + " and the room is " + theAvailibility + ".\n";
		} */
	}

}

void Hotel::showGuests() {
	for (Guest* guest : guests) {
		cout << guest->getFirstName() << " " << guest->getLastName() << endl;
	}
}


