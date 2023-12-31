#ifndef NORMALROOM_H
#define NORMALROOM_H

#include "Room.h"
#include "Headers.h"

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

#endif