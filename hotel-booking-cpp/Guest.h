#pragma once
class Guest {
	string firstName, lastName, email, bookingNum, roomNum;
	int id, phone, floorNum, inDate, outDate;

	void expand();

public:
	Guest(string email, string firstName = "", string lastName = "", int phone = 0);
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

	bool editGuest(int id, string firstName, string email, string lastName = "", int phone = 0);
	bool removeGuest(int id);

	bool createReservation(string bookingNum = "", string roomNum = "", int floorNum = 0, int inDate = 0, int outDate = 0);
	bool editReservation(int id, string bookingNum = "", string roomNum = "", int floorNum = 0, int inDate = 0, int outDate = 0);
	bool removeReservation(int id);


};

