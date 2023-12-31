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

string Spa::printRoomInfo() {
	return string();
}
