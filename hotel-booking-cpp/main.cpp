#pragma once
#include "Headers.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "FileManager.h"
#include "Functions.h"
#include "NormalRoom.h"



int main() {
	FileManager fm;
	fm.setFilename("hotels.txt");

	Hotel hotel;

	NormalRoom* norm1 = new NormalRoom(12, true);
	hotel.addRoom(*norm1);
	hotel.showRooms();

	return 0;
}