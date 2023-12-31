#include "ManageString.h"

ManageString::ManageString() {}

ManageString::~ManageString() {}

//check if number or string
bool ManageString::is_number(string str) {
	if (str == "") return false;
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}



// Split the string according to the character
vector<string> ManageString::split(string str, string seperator) {
	size_t pos_start = 0, pos_end, delim_len = seperator.length();
	string tempStr;
	vector<string> splited;

	while ((pos_end = str.find(seperator, pos_start)) != string::npos) {
		tempStr = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		splited.push_back(tempStr);
	}

	splited.push_back(str.substr(pos_start));
	return splited;
}
