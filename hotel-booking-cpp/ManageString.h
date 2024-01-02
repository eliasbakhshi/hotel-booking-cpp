#pragma once
#include "Headers.h"
#include "Hotel.h"


class ManageString {
public:
	bool is_number(string str);
	ManageString();
	~ManageString();
	vector<string> split(string str, string seperator = " ");

};

