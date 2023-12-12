#pragma once
#include "FileManager.h"

string* FileManager::readFile(string filename) {
	int rowCount = 0;
	string rowContent;

	ifstream inStream(filename);
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

int* FileManager::countFilerows(string filename) {
	int* rowNums = new int(0);
	string tempInput;
	ifstream theFile(filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)) {
			if (!tempInput.empty())
				*rowNums = *rowNums + 1;
		}
		theFile.close();
		return rowNums;
	}
	return 0;
}

bool FileManager::saveToFile(string filename, Guest& info) {
	ofstream of(filename);
	if (of.is_open()) {
		of << info.getEmail() + '|';
		return true;
	}
	return false;
}

int FileManager::getLastId(string filename) {
	return 0;
}
