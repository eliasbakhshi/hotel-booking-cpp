#pragma once
#include "Headers.h"
#include "ManageString.h"


class ManageInputs : private ManageString {

public:
	string get_string(string message = "", bool acceptEmptyString = false);
	int get_int(string message);
	float get_float(string message);
};

