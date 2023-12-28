#ifndef MANAGESTRING_H
#define MANAGESTRING_H

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
	//string guestToS(const Guest& info);
	//string hotelToS(Booking& info);

};

#endif