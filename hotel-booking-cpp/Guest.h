#pragma once
class Guest {
	string firstName, lastName, email, bookingNum, roomNum;
	int phone, floorNum, inDate, outDate;

	Guest();
	Guest(const Guest& other);
	~Guest();

	void operator=(const Guest& other);

	string getFirstName();
	void setFirstName(string newFirstName);
	string getLastName();
	void setLastName(string newLastName);
	string getEmail();
	void setEmail(string newEmail);
	string getBookingNum();
	void setBookingNum(string newBookingNum);
	string getRoomNum();
	void setRoomNum(string newRoomNum);
	int getPhone();
	void setPhone(int newPhone);
	int getFloorNum();
	void setFloorNum(int newFloorNum);
	int getInDate();
	void setInDate(int newInDate);
	int getOutDate();
	void setOutDate(int newOutDate);

	bool createBooking();


};

