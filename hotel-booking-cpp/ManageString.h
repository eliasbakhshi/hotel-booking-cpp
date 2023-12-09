#pragma once
#include "Headers.h"


class ManageString {
protected:
	bool is_number(string str);
public:
	string* split(string str, char ch = ' ');
};
