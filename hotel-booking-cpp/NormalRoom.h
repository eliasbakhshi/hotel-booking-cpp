#pragma once

#include "Headers.h"
#include "Room.h"
#include "ManageString.h"
#include "ManageInputs.h"

class NormalRoom : public Room{
private:
	string minibar[3];
public:
	NormalRoom(int id, int number, int floor, int size);
	NormalRoom();
	string getMinibarContent();
	void showMinibarContent();

	string getRoomInfo() override;
};

