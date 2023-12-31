#ifndef SPA_H
#define SPA_H

#include "Room.h"
#include "Headers.h"

class Spa : public Room{
private:
	bool isVip;
public:
	Spa(bool isVip);
	Spa();
	~Spa();
	int generateCustomEntryCode();
	void setIsVip(bool isVip);
	bool getIsVip();

	string printRoomInfo() override;
};

#endif