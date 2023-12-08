#ifndef HOTEL_H
#define HOTEL_H

class Hotel {
private:
	int roomNr;
	int floor;
public:
	Hotel();
	Hotel(int roomNr, int floor);
	virtual ~Hotel();
	virtual int getFloor() = 0;
	virtual void setFloor(int floor) = 0;
	int getRoom();
	void setRoom(int roomNr);
}; 

#endif