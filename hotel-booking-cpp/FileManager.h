#pragma once
#include "Headers.h"
#include "ManageString.h"

class FileManager{
	string filename;

public:
	FileManager(string filename = "");
	~FileManager();
	void setFilename(string filename);
	string getFilename();
	int insert(string info, string filename = "");
	vector<string> select(string value, string filename = "");
	vector<string> selectByIndex(string value, int index, string filename = "");
	vector<string> selectAll(string filename = "");
	vector<string> selectAllByIndex(string value, int index, string filename = "");
	bool update(int id, string info, string filename = "");
	bool remove(int id, string filename = "");
	int getLastId(string filename = "");
};

