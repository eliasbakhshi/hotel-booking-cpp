#pragma once
#include "Headers.h"

class Building {
	// TODO: Maybe need to add totalfloors, totalrooms and list of rooms
	int id;
	string address;

public:
	Building(int id, string address);
	virtual ~Building();
	int getId();
	void setId(int id);
	string getAddress();
	void setAddress(string address);
	virtual string toString() = 0;
};

