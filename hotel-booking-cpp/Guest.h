#pragma once
#include "Headers.h"
#include "FileManager.h"

class Guest {
	string firstName, lastName, email, phone, bookingNum, password;
	int id = 1;

	void expand();

public:
	Guest(string email = "", string firstName = "Guest user", string lastName = "", string phone = "", string bookingNum = "");
	Guest(const Guest& other);
	~Guest();

	void operator=(const Guest& other);

	int getId() const;
	void setId(int id);
	string getFirstName() const;
	void setFirstName(string newFirstName);
	string getLastName() const;
	void setLastName(string newLastName);
	string getEmail() const;
	void setEmail(string newEmail);
	string getPhone() const;
	void setPhone(string newPhone);
	string getBookingNum() const;
	void setBookingNum(string bookingNum);
	string getPassword();
	void setPassword(string password);


	bool editGuest(int id, string firstName, string email, string lastName = "", string phone = 0);
	bool removeGuest(int id);



};

