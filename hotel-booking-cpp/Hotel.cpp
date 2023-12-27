#include "Hotel.h"

Hotel::Hotel() {
	this->phone = "";
	this->floor = 0;
}

Hotel::Hotel(int roomNr, int floor) {
	this->phone = roomNr;
	this->floor = floor;
}

Hotel::~Hotel() {
}

int Hotel::getId() {
	return this->id;
}

void Hotel::setId(int id) {
	this->id = id;
}

string Hotel::getPhone() {
	return this->phone;
}

void Hotel::setPhone(string number) {
	this->phone = number;
}

string Hotel::toString() {
	return string();
}
