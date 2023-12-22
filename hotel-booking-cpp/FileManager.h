#pragma once
#include "Headers.h"
#include "Guest.h"
#include "ManageString.h"

class FileManager {
	string filename;

public:
	FileManager(string filename = "");
	~FileManager();
	int insert(Guest& info, string filename = "");
	vector<string> select(int id = 0, string filename = "");
	bool update(int id, Guest& info, string filename = "");
	bool update(int id, string email = "", string firstName = "", string lastName = "", int phone = 0, string filename = "");
	bool remove(int id, string filename = "");
	//int countRows(string filename = "");
	int getLastId(string filename = "");
};

