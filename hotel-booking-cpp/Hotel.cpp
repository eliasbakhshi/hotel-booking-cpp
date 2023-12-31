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

//void Hotel::setGuest(Guest* guest) {
//    this->guest = guest;
//}

string Hotel::getName() {
    return this->name;
}

string Hotel::getCity() {
    return this->city;
}

string Hotel::getCountry() {
    return this->country;
}

//Guest* Hotel::getGuest() {
//    return this->guest;
//}

void Hotel::addRoom(Room * room) {
    rooms.push_back(room);
}


void Hotel::showRooms()  {
    for (Room* room : rooms) {
        string theAvailibility = to_string(room->getIsAvailable()) = "1" ? "available" : "is not available";
        cout << "The room number is: " + to_string(room->getRoomNum()) + " and the room is " + theAvailibility + ".\n";
    }
}
