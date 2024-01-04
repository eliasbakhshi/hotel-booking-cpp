#pragma once

#include "Headers.h"
#include "Room.h"

class NormalRoom : public Room{
private:
	string minibar[3];
public:
	NormalRoom(int id, int number, int floor, int size);
	NormalRoom();
	void addMinibarContent();
	void showMinibarContent();

	string getRoomInfo() override;
};

