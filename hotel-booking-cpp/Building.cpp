#include "Building.h"

Building::Building(int id, string address): id(id), address(address) {}

Building::~Building() {}

int Building::getId() {
	return this->id;
}

void Building::setId(int id) {
	this->id = id;
}

string Building::getAddress() {
	return this->address;
}

void Building::setAddress(string address) {
	this->address = address;

}
