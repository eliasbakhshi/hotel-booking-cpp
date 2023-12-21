#pragma once
#include "FileManager.h"

ManageString ms;

FileManager::FileManager(string filename) {
	this->filename = filename;
}

FileManager::~FileManager() {}



bool FileManager::insert(Guest& info, string filename) {
	if (filename != "")
		this->filename = filename;
	ofstream of(this->filename, ios::app);
	if (of.is_open()) {
		of << '\n' << this->getLastId() + 1 << '|' << info.getFirstName() << '|' << info.getLastName() << '|' << info.getPhone();
		return true;
	}
	return false;
}

vector<string> FileManager::select(int id, string filename) {
	if (filename != "")
		this->filename = filename;
	string rowContent;

	vector<string> tempArray;
	ifstream inStream(this->filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) { // Get the amount of rows.
			if (!rowContent.empty()) {
				if (id != 0) {
					tempArray.push_back(rowContent);
				} else { // the the row with the given id
					//ms.split(rowContent);
				}
			}
		}
		inStream.close();
	} else {
		tempArray.push_back("Could not read the file.");
	}
	return tempArray;
}

bool FileManager::update(Guest& info, string filename) {
	if (filename != "")
		this->filename = filename;
	return false;
}

bool FileManager::remove(int id, string filename) {
	if (filename != "")
		this->filename = filename;
	// Get lines as a vector
	vector<string> lines;
	string tempInput;
	bool deleted = false;
	ifstream iFile(this->filename);
	if (iFile.is_open()) {
		while (getline(iFile, tempInput)) {
			if (!tempInput.empty()) {
				lines.push_back(tempInput);
			}
		}
		iFile.close();
	}
	// Replace the info back but with out the row that we wanted
	ofstream oFile(this->filename);
	if (oFile.is_open()) {
		vector<string> cols;
		for (int i = 0; i < lines.size(); i++) {
			cols = ms.split(lines[i], "|");
			cout << typeid((cols)[0]).name() << endl;
			if (stoi(cols[0]) != id) {

			}
			cout << lines[i];
		}
	}



	deleted = true;


	return deleted;
}

int FileManager::countRows(string filename) {
	if (filename != "")
		this->filename = filename;
	int rowNums = 0;
	string tempInput;
	ifstream theFile(this->filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)) {
			if (!tempInput.empty())
				rowNums = rowNums + 1;
		}
		theFile.close();
		return rowNums;
	}
	return 0;
}
int FileManager::getLastId(string filename) {
	if (filename != "")
		this->filename = filename;
	string tempInput;
	vector<string> tempList;
	ifstream theFile(this->filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)) {}
		tempList = ms.split(tempInput, "|");
		theFile.close();
		if (tempList[0] != "")
			return stoi(tempList[0]);
	}
	return 0;
}