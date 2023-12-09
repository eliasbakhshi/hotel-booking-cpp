#pragma once
#include "Headers.h"


class ManageString {
protected:
	bool is_number(string str);
public:
	ManageString();
	~ManageString();
	string* split(string str, char ch = ' ');
};
