#pragma once
#include "Headers.h"


class FileManager {
	string color = "";

public:
	bool saveToFile(string filename, string names[], float scores[], int length);
	int* countFilerows(string filename);
	string* readFile(string filename);

};

