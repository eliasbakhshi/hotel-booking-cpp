#include "FileManager.h"

ManageString msFile;

FileManager::FileManager(string filename) {
	this->filename = filename;
}

FileManager::~FileManager() {}

void FileManager::setFilename(string filename) {
	this->filename = filename;
}

string FileManager::getFilename() {
	return this->filename;
}

int FileManager::insert(string info, string filename) {
	if (filename != "")
		this->filename = filename;
	ofstream of(this->filename, ios::app);
	if (of.is_open()) {
		int id = this->getLastId() + 1;
		of << info;
		return id;
	}
	return 0;
}

vector<string> FileManager::select(string id, string filename) {
	if (filename != "")
		this->filename = filename;
	string rowContent;

	vector<string> tempArray;
	ifstream inStream(this->filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) {
			if (!rowContent.empty()) {// the the row with the given id
				if (msFile.split(rowContent, "|")[0] == id) {
					inStream.close();
					tempArray.push_back(rowContent);
					return tempArray;
				}
			}
		}
		inStream.close();
	} else {
		tempArray.push_back("Could not read the file.");
	}
	return tempArray;
}

vector<string> FileManager::selectByIndex(string value, int index, string filename) {
	if (filename != "")
		this->filename = filename;
	string rowContent;

	vector<string> tempArray, theArray;
	ifstream inStream(this->filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) {
			if (!rowContent.empty()) {// the the row with the given value
				tempArray = msFile.split(rowContent, "|");
				if (tempArray[index] == value) {
					inStream.close();
					return tempArray;
				}
			}
		}
		inStream.close();
		theArray.push_back("");
	} else {
		theArray.push_back("Could not read the file.");
	}
	return theArray;
}

vector<string> FileManager::selectAll(string filename) {
	if (filename != "")
		this->filename = filename;
	string rowContent;

	vector<string> tempArray;
	ifstream inStream(this->filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) {
			if (!rowContent.empty()) { // Save all the rows
				tempArray.push_back(rowContent);
			}
		}
		inStream.close();
	} else {
		tempArray.push_back("Could not read the file.");
	}
	return tempArray;
}

vector<string> FileManager::selectAllByIndex(string value, int index, string filename) {
	if (filename != "")
		this->filename = filename;
	string rowContent;

	vector<string> tempArray, theArray;
	ifstream inStream(this->filename);
	if (inStream.is_open()) {
		while (getline(inStream, rowContent)) {
			if (!rowContent.empty()) {// the the row with the given value
				tempArray = msFile.split(rowContent, "|");
				if (tempArray[index] == value) {
					theArray.push_back(rowContent);
				}
			}
		}
		return theArray;
		inStream.close();
	} else {
		theArray.push_back("Could not read the file.");
	}
	return theArray;
}

bool FileManager::update(int id, string infoRow, string filename) {
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
			if (stoi(msFile.split(lines[i], "|")[0]) != id) {
				oFile << lines[i] << endl;
			} else { // Update the row with the given id in the file.
				oFile << infoRow;
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
			if (stoi(msFile.split(lines[i], "|")[0]) != id) {
				oFile << lines[i] << endl;
			} else {
				deleted = true;
			}
		}
	}
	return deleted;
}

// Get the last ID in the file.
int FileManager::getLastId(string filename) {
	ManageString msFileManager;
	if (filename != "")
		this->filename = filename;
	string tempInput;
	vector<string> tempList;
	ifstream theFile(this->filename);
	if (theFile.is_open()) {
		while (getline(theFile, tempInput)) {
			if (tempInput != "") {
				tempList = msFile.split(tempInput, "|");
			}
		}
		theFile.close();
		if (tempList[0] != "" && msFileManager.is_number(tempList[0]))
			return stoi(tempList[0]);
	}
	return 0;
}