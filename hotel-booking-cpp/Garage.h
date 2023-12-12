#ifndef GARAGE_H
#define GARAGE_H
#include "Hotel.h"

class Garage : public Hotel {
private:
	int id;
	int placeNum;
	int floor;
public:
	int getId();
	void setId(int id);
	int getPlaceNum();
	void setPlaceNum(int placeNum);
	virtual int getFloor() override;
	virtual void setFloor(int floor) override;
};

#endif