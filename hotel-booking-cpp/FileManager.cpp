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
		//of.seekp(-1, ios::end);
		of << '\n' << this->getLastId() + 1 << '|' << info.getFirstName() << '|' << info.getLastName() << '|' << info.getPhone();
		return true;
	}
	return false;
}

string* FileManager::select(string filename) {
	if (filename != "")
		this->filename = filename;
	int rowCount = 0;
	string rowContent;

	ifstream inStream(this->filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) { // Get the amount of rows.
			if (!rowContent.empty()) {
				rowCount++;
			}
		}
		inStream.clear();
		inStream.seekg(0, ios_base::beg);

		string* tempArray = new string[rowCount];
		for (int i = 0; i < rowCount; i++) {
			getline(inStream, tempArray[i]);
		}
		inStream.close();
		return tempArray;
	} else {
		string* message = new string[1]{ "Could not read the file." };
		return message;
	}
}

bool FileManager::update(Guest& info, string filename) {
	if (filename != "")
		this->filename = filename;
	return false;
}

bool FileManager::remove(int id, string filename) {
	if (filename != "")
		this->filename = filename;
	return false;
}

int FileManager::countRows(string filename) {
	if (filename != "")
		this->filename = filename;
	int* rowNums = new int(0);
	string tempInput;
	ifstream theFile(this->filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)) {
			if (!tempInput.empty())
				*rowNums = *rowNums + 1;
		}
		theFile.close();
		return *rowNums;
	}
	return 0;
}
int FileManager::getLastId(string filename) {
	if (filename != "")
		this->filename = filename;
	string tempInput;
	string* tempList;
	ifstream theFile(this->filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)){}
		tempList = ms.split(tempInput, '|');
		theFile.close();
		return stoi(tempList[0]);
	}
	return 0;
}