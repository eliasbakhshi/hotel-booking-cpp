#include "Guest.h"

FileManager fmGuest;

void Guest::expand() {}


Guest::Guest(string email, string firstName, string lastName, string phone, string bookingNum) : email(email), firstName(firstName), lastName(lastName), phone(phone), bookingNum(bookingNum) {
	//this->id = fm.getLastId("guests.txt");
}

Guest::Guest(const Guest& other) : id(other.id), email(other.email), firstName(other.firstName),
lastName(other.lastName), phone(other.phone) {}
Guest::~Guest() {}
void Guest::operator=(const Guest& other) {}

string Guest::getFirstName() const{
	return firstName;
}

void Guest::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Guest::getLastName() const{
	return lastName;
}

void Guest::setLastName(string lastName) {
	this->lastName = lastName;
}

string Guest::getEmail() const{
	return email;
}

void Guest::setEmail(string email) {
	this->email = email;
}

int Guest::getId() const{
	return this->id;
}

void Guest::setId(int id) {
	this->id = id;
}

string Guest::getPhone() const{
	return phone;
}

void Guest::setPhone(string phone) {
	this->phone = phone;
}

string Guest::getBookingNum() const{
	return this->bookingNum;
}

void Guest::setBookingNum(string bookingNum) {
	this->bookingNum = bookingNum;
}

bool Guest::editGuest(int id, string firstName, string email, string lastName, string phone) {
	return false;
}

bool Guest::removeGuest(int id) {
	return false;
}

