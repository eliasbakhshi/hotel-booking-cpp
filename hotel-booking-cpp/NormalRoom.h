#pragma once

#include "Headers.h"
#include "Room.h"

class NormalRoom : public Room{
private:
	const int roomSize = 22;
	string minibar[3];
public:
	NormalRoom(int roomNum, bool isAvailable = true);
	NormalRoom();
	int getRoomSize();
	void enterMinibarContent();

	string printRoomInfo() override;
};

