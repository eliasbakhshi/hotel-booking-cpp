#pragma once
#include "Room.h"
#include "Headers.h"

class Spa : public Room{
private:
	bool isVip;
public:
	Spa(bool isVip);
	Spa();
	~Spa();
	int generateCustomEntryCode();
	void setIsVip(bool isVip);
	bool getIsVip();

	string getRoomInfo() override;
};

