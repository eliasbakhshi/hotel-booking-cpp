#include "NormalRoom.h"

NormalRoom::NormalRoom(int roomNum, bool isAvailable)
	:Room(roomNum, isAvailable)
{
}

NormalRoom::NormalRoom() {
}

int NormalRoom::getRoomSize() {
	return this->roomSize;
}

void NormalRoom::enterMinibarContent(string item1, string item2, string item3) {
	minibar[0] = item1;
	minibar[1] = item2;
	minibar[2] = item3;

	for (int i = 0; i < 3; i++) {
		cout << minibar[i] << " " << endl;
	}
}
