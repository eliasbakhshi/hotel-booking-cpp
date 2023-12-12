#pragma once
#include "Headers.h"
#include "Guest.h"


class FileManager {
public:

	bool saveToFile(string filename, Guest &info);
	int* countFilerows(string filename);
	string* readFile(string filename);
	int getLastId(string filename);

};

