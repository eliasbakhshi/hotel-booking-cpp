#pragma once
#include "Headers.h"
#include "Guest.h"
#include "ManageString.h"

class FileManager {
	string filename;

public:
	FileManager(string filename = "");
	~FileManager();
	bool insert(Guest& info, string filename = "");
	string* select(string filename = "");
	bool update(Guest& info, string filename = "");
	bool remove(int id, string filename);
	int countRows(string filename = "");
	int getLastId(string filename = "");
};

