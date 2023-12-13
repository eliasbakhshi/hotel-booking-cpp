#include "Headers.h"
#include "Guest.h"
#include "FileManager.h"

FileManager fm;

void Guest::expand() {}


Guest::Guest(string email, string firstName, string lastName, int phone) : email(email), firstName(firstName), lastName(lastName), phone(phone) {
	//this->id = fm.getLastId("guests.txt");
}

Guest::Guest(const Guest& other) : id(other.id), email(other.email), firstName(other.firstName),
lastName(other.lastName), phone(other.phone) {}
Guest::~Guest() {}
void Guest::operator=(const Guest& other) {}

string Guest::getFirstName() {
	return firstName;
}

void Guest::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Guest::getLastName() {
	return lastName;
}

void Guest::setLastName(string lastName) {
	this->lastName = lastName;
}

string Guest::getEmail() {
	return email;
}

void Guest::setEmail(string email) {
	this->email = email;
}

string Guest::getBookingNum() {
	return bookingNum;
}

void Guest::setBookingNum(string bookingNum) {
	this->bookingNum = bookingNum;
}

string Guest::getRoomNum() {
	return roomNum;
}

void Guest::setRoomNum(string roomNum) {
	this->roomNum = roomNum;
}

int Guest::getId() {
	return this->id;
}

void Guest::setId(int id) {
	this->id = id;
}

int Guest::getPhone() {
	return phone;
}

void Guest::setPhone(int phone) {
	this->phone = phone;
}

int Guest::getFloorNum() {
	return floorNum;
}

void Guest::setFloorNum(int floorNum) {
	this->floorNum = floorNum;
}

int Guest::getInDate() {
	return inDate;
}

void Guest::setInDate(int inDate) {
	this->inDate = inDate;
}

int Guest::getOutDate() {
	return outDate;
}

void Guest::setOutDate(int outDate) {
	this->outDate = outDate;
}

bool Guest::editGuest(int id, string firstName, string email, string lastName, int phone) {
	return false;
}

bool Guest::removeGuest(int id) {
	return false;
}

bool Guest::createReservation(string bookingNum, string roomNum, int floorNum, int inDate, int outDate) {
	return false;
}

bool Guest::editReservation(int id, string bookingNum, string roomNum, int floorNum, int inDate, int outDate) {
	return false;
}

bool Guest::removeReservation(int id) {
	return false;
}

