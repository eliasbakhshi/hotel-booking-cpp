#pragma once
#include "Room.h"

Room::Room() {
    this->number = 0;
    this->number = number;
    this->size = size;
    this->type = type;
}

Room::Room(int id, int number, int floor, int size, string type): id(id), number(number), size(size), type(type) {
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


void Room::setSize(int size) {
    this->size = size;
}

void Room::setType(string type) {
    this->type = type;
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

string Room::getType() {
    return this->type;
}

