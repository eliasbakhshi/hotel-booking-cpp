#include "Spa.h"

Spa::Spa(bool isVip) {
	this->isVip = isVip;
}

Spa::Spa() {
	this->isVip = false;
}

Spa::~Spa() {
}

int Spa::generateCustomEntryCode() {
	// Generates a custom entry code for the VIP users
	int entryCode;
	if (this->isVip == true) {
		srand(time(0));
		entryCode = rand() % 10000;
	}
	else {
		cout << "User is not VIP!";
		entryCode = 0;
	}
	return entryCode;
}

void Spa::setIsVip(bool isVip) {
	this->isVip = isVip;
}

bool Spa::getIsVip() {
	return this->isVip;
}

string Spa::getRoomInfo() {
	return to_string(this->getId()) + ") Type: Spa, Number: " + to_string(this->getNumber()) + ", Size: " + to_string(this->getSize()) + "sqm";
}
