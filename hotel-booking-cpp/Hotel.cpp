#include "Hotel.h"

FileManager fmHotel;
ManageString msHotel;

Hotel::Hotel(string name, string city, string country) {
	this->name = name;
	this->city = city;
	this->country = country;
}

Hotel::Hotel(int hotelId) {
	this->hotelId = hotelId;
	vector<string> theHotel = fmHotel.selectByIndex(to_string(hotelId), 0, "hotels.txt");

	this->name = theHotel[1];
	this->country = theHotel[2];
	this->city = theHotel[3];
	this->address = theHotel[4];

	vector<string> rooms = fmHotel.selectAllByIndex(to_string(hotelId), 4, "rooms.txt");
	for (int i = 0; i < rooms.size(); i++) {
		vector<string> line = msHotel.split(rooms[i], "|");
		if (line[5] == "normal") {
			this->addNormalRoom(stoi(line[0]), stoi(line[1]), stoi(line[2]), stoi(line[3]));
		} else if (line[5] == "vip") {
			this->addVipRoom(stoi(line[0]), stoi(line[1]), stoi(line[2]), stoi(line[3]));
		}
	}
}

Hotel::~Hotel() {}

void Hotel::setHotelId(int id) {
	this->hotelId = hotelId;
}

void Hotel::setName(string name) {
	this->name = name;
}

void Hotel::setCity(string city) {
	this->city = city;
}

void Hotel::setCountry(string country) {
	this->country = country;
}

void Hotel::setAddress(string address) {
	this->address = address;
}

void Hotel::addGuest(Guest guest) {
	unique_ptr<Guest> guestPtr = make_unique<Guest>(move(guest));
	this->guests.push_back(move(guestPtr));
}

int Hotel::getHotelId() {
	return this->hotelId;
}

string Hotel::getName() {
	return this->name;
}

string Hotel::getCity() {
	return this->city;
}

string Hotel::getCountry() {
	return this->country;
}

string Hotel::getAddress() {
	return this->address;
}

vector<unique_ptr<Guest>> Hotel::getGuests() {
	return move(this->guests);
}

void Hotel::addNormalRoom(int id, int roomNum, int floor, int size) {
	rooms.push_back(make_unique<NormalRoom>(id, roomNum, floor, size));
}

void Hotel::addVipRoom(int id, int roomNum, int floor, int size) {
	rooms.push_back(make_unique<VipRoom>(id, roomNum, floor, size));
}


int Hotel::showRooms() {
	for (int i = 0; i < rooms.size(); i++) {
		cout << rooms[i]->getRoomInfo() << endl;
	}
	return rooms.size();
}

int Hotel::showOptions(int roomId) {
	NormalRoom* normalr = dynamic_cast<NormalRoom*>(rooms[roomId].get());
	VipRoom* vipr = dynamic_cast<VipRoom*>(rooms[roomId].get());

	if (normalr) {
		cout << "The room number is: " + to_string(rooms[roomId]->getNumber()) + ".\n";
	} else if (vipr) {
		cout << "The room number is: " + to_string(rooms[roomId]->getNumber()) + ".\n";
	}

	return 0;
}

void Hotel::showGuests() const {
	for (const auto& guestPtr : guests) {
		cout << guestPtr->getFirstName() << " " << guestPtr->getLastName() << endl;
	}
}

bool Hotel::removeGuest(int id) {
	bool isDeleted = false;

	for (auto it = guests.begin(); it != guests.end(); ++it) {
		if (id == (*it)->getId()) {
			it = guests.erase(it);
			isDeleted = true;
			--it;
			break;
		}
	}
	return isDeleted;
}