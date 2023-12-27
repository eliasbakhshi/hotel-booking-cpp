#pragma once
#include "Headers.h";
#include "Building.h";

class Booking: public Building {
	int id = 1, inDate, outDate;

public:
	Booking();
	~Booking();
	//string getRoomNum();
	//void setRoomNum(string newRoomNum);
	int getId();
	void setId(int id);
	//int getFloorNum();
	//void setFloorNum(int newFloorNum);
	int getInDate();
	void setInDate(int newInDate);
	int getOutDate();
	void setOutDate(int newOutDate);

	bool createReservation(int id, string roomNum = "", int floorNum = 0, int inDate = 0, int outDate = 0);
	bool editReservation(int id,string roomNum = "", int floorNum = 0, int inDate = 0, int outDate = 0);
	bool removeReservation(int id);

};

