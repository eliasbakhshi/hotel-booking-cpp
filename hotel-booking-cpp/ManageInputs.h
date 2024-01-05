#pragma once
#include "Headers.h"
#include "ManageString.h"

class ManageInputs {

public:
	ManageInputs();
	~ManageInputs();
	string get_string(string message = "", bool acceptEmptyString = false);
	int get_int(string message, size_t minRange = 0, size_t maxRange = 0);
	float get_float(string message);
};

