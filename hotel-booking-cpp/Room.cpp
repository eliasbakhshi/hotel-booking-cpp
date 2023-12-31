#pragma once
#include "Room.h"

Room::Room() {
    this->number = 0;
    this->number = number;
    this->size = size;
    this->isAvailable = isAvailable;
}

Room::Room(int id, int number, int size, bool isAvailable): id(id), number(number), size(size), isAvailable(isAvailable) {
}

Room::~Room() {
}

void Room::setId(int id) {
    this->id = id;
}

void Room::setNumber(int number) {
    this->number = number;
}

void Room::setFloor(int floor) {
    this->floor = floor;
}

void Room::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void Room::setSize(int size) {
    this->size = size;
}

int Room::getId() {
    return this->id;
}

int Room::getFloor() {
    return this->floor;
}

int Room::getNumber() {
    return this->number;
}

int Room::getSize() {
    return this->size;
}

bool Room::getIsAvailable() {
    return this->isAvailable;
}
