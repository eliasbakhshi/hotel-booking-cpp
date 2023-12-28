#pragma once
#include "Headers.h"
#include "Guest.h"
#include "Hotel.h"


class ManageString {
protected:
	bool is_number(string str);
public:
	ManageString();
	~ManageString();
	vector<string> split(string str, string seperator = " ");
	//string guestToS(Guest& info);
	//string hotelToS(Booking& info);

};
