#pragma once

#include "Headers.h"
#include "Room.h"

class NormalRoom : public Room{
private:
	string minibar[3];
public:
	NormalRoom(int id, int number, int size, bool isAvailable = true);
	NormalRoom();
	void enterMinibarContent();

	string getRoomInfo() override;
};

