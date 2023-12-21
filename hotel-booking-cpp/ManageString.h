#pragma once
#include "Headers.h"


class ManageString {
protected:
	bool is_number(string str);
public:
	ManageString();
	~ManageString();
	vector<string> split(string str, string seperator = " ");

};
