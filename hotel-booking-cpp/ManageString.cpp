#pragma once
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
string* ManageString::split(string str, char ch) {
	int count = 1;
	string tempStr = "";
	string* splited = nullptr;
	// Count have many of char exists in the string
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ch) count++;
	}

	splited = new string[count];
	if (count == 1) {
		splited[0] = str;
	} else {
		int j = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ch) {
				splited[j] += str[i];
			} else {
				j++;
			}
		}
	}
	return splited;
}