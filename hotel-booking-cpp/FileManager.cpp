#pragma once
#include "FileManager.h"

ManageString ms;

FileManager::FileManager(string filename) {
	this->filename = filename;
}

FileManager::~FileManager() {}



int FileManager::insert(Guest& info, string filename) {
	if (filename != "")
		this->filename = filename;
	ofstream of(this->filename, ios::app);
	if (of.is_open()) {
		int id = this->getLastId() + 1;
		of << '\n' << id << '|' << info.getFirstName() << '|' << info.getLastName() << '|' << info.getEmail() << '|' << info.getPhone();
		return id;
	}
	return 0;
}

vector<string> FileManager::select(int id, string filename) {
	if (filename != "")
		this->filename = filename;
	string rowContent;

	vector<string> tempArray;
	ifstream inStream(this->filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) {
			if (!rowContent.empty()) {
				if (id == 0) { // Return all the rows
					tempArray.push_back(rowContent);
				} else { // the the row with the given id
					tempArray = ms.split(rowContent, "|");
					if (stoi(tempArray[0]) == id) {
						inStream.close();
						return tempArray;
					}
				}
			}
		}
		inStream.close();
	} else {
		tempArray.push_back("Could not read the file.");
	}
	return tempArray;
}

bool FileManager::update(int id, Guest& info, string filename) {
	if (filename != "")
		this->filename = filename;
	// Get lines as a vector
	vector<string> lines;
	string tempInput;
	bool updated = false;
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
		for (int i = 0; i < lines.size(); i++) {
			if (stoi(ms.split(lines[i], "|")[0]) != id) {
				oFile << lines[i] << endl;
			} else {
				oFile << id << '|' << info.getFirstName() << '|' << info.getLastName() << '|' << info.getEmail() << '|' << info.getPhone() << endl;
				updated = true;
			}
		}
	}
	return updated;
}

bool FileManager::update(int id, string email, string firstName, string lastName, int phone, string filename) {
	if (filename != "")
		this->filename = filename;
	// Get lines as a vector
	vector<string> lines, line;
	string tempInput;
	bool updated = false;
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
		for (int i = 0; i < lines.size(); i++) {
			line = ms.split(lines[i], "|");
			if (stoi(line[0]) != id) {
				oFile << lines[i] << endl;
			} else {
				if (firstName == "") firstName = line[1];
				if (lastName == "") lastName = line[2];
				if (email == "") email = line[3];
				if (phone == 0) phone = stoi(line[4]);

				oFile << id << '|' << firstName << '|' << lastName << '|' << email << '|' << to_string(phone) << endl;
				updated = true;
			}
		}
	}
	return updated;
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
		for (int i = 0; i < lines.size(); i++) {
			if (stoi(ms.split(lines[i], "|")[0]) != id) {
				oFile << lines[i] << endl;
			} else {
				deleted = true;
			}
		}
	}
	return deleted;
}

//int FileManager::countRows(string filename) {
//	if (filename != "")
//		this->filename = filename;
//	int rowNums = 0;
//	string tempInput;
//	ifstream theFile(this->filename);
//	if (theFile.is_open()) {
//		while (getline(theFile, tempInput)) {
//			if (!tempInput.empty())
//				rowNums = rowNums + 1;
//		}
//		theFile.close();
//		return rowNums;
//	}
//	return 0;
//}

// Get the last ID in the file.
int FileManager::getLastId(string filename) {
	if (filename != "")
		this->filename = filename;
	string tempInput;
	vector<string> tempList;
	ifstream theFile(this->filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)) {
			if (tempInput != "") {
				tempList = ms.split(tempInput, "|");
			}
		}
		theFile.close();
		if (tempList[0] != "")
			return stoi(tempList[0]);
	}
	return 0;
}