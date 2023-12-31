#pragma once
#include "Room.h"

Room::Room() {
    this->roomNum = 0;
    this->isAvailable = false;
}

Room::Room(int roomNum, bool isAvailable) {
    this->roomNum = roomNum;
    this->isAvailable = isAvailable;
}

Room::~Room() {
}

void Room::setRoomNum(int roomNum) {
    this->roomNum = roomNum;
}

void Room::setFloor(int floor) {
    this->floor = floor;
}

void Room::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

int Room::getFloor() {
    return this->floor;
}

int Room::getRoomNum() {
    return this->roomNum;
}

bool Room::getIsAvailable() {
    return this->isAvailable;
}
