#ifndef HOTEL_H
#define HOTEL_H

class Hotel {
private:
	int roomNr;
	int floor;
public:
	virtual int getFloor() = 0;
	virtual void setFloor(int floor) = 0;
	virtual int getRoom() = 0;
	virtual void setRoom(int roomNr) = 0;
}; 

#endif