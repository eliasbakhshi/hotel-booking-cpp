#include "Booking.h"

Booking::Booking() {}

Booking::~Booking() {}
//
//string Booking::getRoomNum() {
//	return string();
//}
//
//void Booking::setRoomNum(string newRoomNum) {}

int Booking::getId() {
	return this->id;
}

void Booking::setId(int id) {
	this->id = id;
}

//int Booking::getFloorNum() {
//	return floorNum;
//}
//
//void Booking::setFloorNum(int floorNum) {
//	this->floorNum = floorNum;
//}
//
//string Booking::getRoomNum() {
//	return roomNum;
//}
//
//void Booking::setRoomNum(string roomNum) {
//	this->roomNum = roomNum;
//}

int Booking::getInDate() {
	return inDate;
}

void Booking::setInDate(int inDate) {
	this->inDate = inDate;
}

int Booking::getOutDate() {
	return outDate;
}

void Booking::setOutDate(int outDate) {
	this->outDate = outDate;
}

bool Booking::createReservation(int id, string roomNum, int floorNum, int inDate, int outDate) {
	return false;
}

bool Booking::editReservation(int id, string roomNum, int floorNum, int inDate, int outDate) {
	return false;
}

bool Booking::removeReservation(int id) {
	return false;
}
