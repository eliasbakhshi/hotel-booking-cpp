#pragma once
#include "Headers.h"
#include "FileManager.h"

class Guest {
	string firstName, lastName, email, phone;
	int id = 1;

	void expand();

public:
	Guest(string email = "", string firstName = "", string lastName = "", string phone = 0);
	Guest(const Guest& other);
	~Guest();

	void operator=(const Guest& other);

	int getId();
	void setId(int id);
	string getFirstName();
	void setFirstName(string newFirstName);
	string getLastName();
	void setLastName(string newLastName);
	string getEmail();
	void setEmail(string newEmail);
	string getPhone();
	void setPhone(string newPhone);

	bool editGuest(int id, string firstName, string email, string lastName = "", string phone = 0);
	bool removeGuest(int id);



};

