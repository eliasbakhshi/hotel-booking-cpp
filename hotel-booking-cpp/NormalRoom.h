#ifndef NORMALROOM_H
#define NORMALROOM_H

#include "Room.h"

class NormalRoom : public Room{

public:
	NormalRoom(int roomNum, bool isAvailable = true);
};

#endif