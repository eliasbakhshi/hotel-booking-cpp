#include "Guest.h"

FileManager fm;

void Guest::expand() {}


Guest::Guest(string email, string firstName, string lastName, string phone) : email(email), firstName(firstName), lastName(lastName), phone(phone) {
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

int Guest::getId() {
	return this->id;
}

void Guest::setId(int id) {
	this->id = id;
}

string Guest::getPhone() {
	return phone;
}

void Guest::setPhone(string phone) {
	this->phone = phone;
}

bool Guest::editGuest(int id, string firstName, string email, string lastName, string phone) {
	return false;
}

bool Guest::removeGuest(int id) {
	return false;
}

