#include "Headers.h"
#include "Guest.h"

Guest::Guest() {}
Guest::Guest(const Guest& other) {}
Guest::~Guest() {}
void Guest::operator=(const Guest& other) {}

string Guest::getFirstName() {
	return firstName;
}

void Guest::setFirstName(string newFirstName) {
	firstName = newFirstName;
}

string Guest::getLastName() {
	return lastName;
}

void Guest::setLastName(string newLastName) {
	lastName = newLastName;
}

string Guest::getEmail() {
	return email;
}

void Guest::setEmail(string newEmail) {
	email = newEmail;
}

string Guest::getBookingNum() {
	return bookingNum;
}

void Guest::setBookingNum(string newBookingNum) {
	bookingNum = newBookingNum;
}

string Guest::getRoomNum() {
	return roomNum;
}

void Guest::setRoomNum(string newRoomNum) {
	roomNum = newRoomNum;
}

int Guest::getPhone() {
	return phone;
}

void Guest::setPhone(int newPhone) {
	phone = newPhone;
}

int Guest::getFloorNum() {
	return floorNum;
}

void Guest::setFloorNum(int newFloorNum) {
	floorNum = newFloorNum;
}

int Guest::getInDate() {
	return inDate;
}

void Guest::setInDate(int newInDate) {
	inDate = newInDate;
}

int Guest::getOutDate() {
	return outDate;
}

void Guest::setOutDate(int newOutDate) {
	outDate = newOutDate;
}

bool Guest::createBooking() {
	return false;
}
