#include "Hotel.h"

Hotel::Hotel() {
	this->number = 0;
	this->floor = 0;
}

Hotel::Hotel(int roomNr, int floor) {
	this->number = roomNr;
	this->floor = floor;
}

Hotel::~Hotel() {
}

int Hotel::getNumber() {
	return this->number;
}

void Hotel::setNumber(int number) {
	this->number = number;
}
