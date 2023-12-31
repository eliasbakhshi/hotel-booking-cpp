#pragma once
#include "Headers.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "FileManager.h"
#include "Functions.h"
#include "NormalRoom.h"



int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Guest guest;
	//menu(guest);

	Hotel hotel;
	/*FileManager fm;
	ManageString ms;
	fm.setFilename("hotels.txt");
	vector<string> hotels = fm.selectAll();
	for (int i = 0; i < hotels.size(); i++) {
		vector<string> line = ms.split(hotels[i], "|");
		cout << line[0] << ": " << line[1] << ", " << line[2] << ", " << line[3] << ". \n";
	}*/
	NormalRoom* norm1 = new NormalRoom(15, true);
	hotel.addRoom(norm1);
	hotel.showRooms();

	return 0;
}