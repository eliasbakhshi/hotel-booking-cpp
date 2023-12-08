#include "Hotel.h"

Hotel::Hotel() {
	this->roomNr = 0;
	this->floor = 0;
}

Hotel::Hotel(int roomNr, int floor) {
	this->roomNr = roomNr;
	this->floor = floor;
}

Hotel::~Hotel() {
}

int Hotel::getRoom() {
	return this->roomNr;
}

void Hotel::setRoom(int roomNr) {
	this->roomNr = roomNr;
}
