#include "Hotel.h"

FileManager fmHotel;
ManageString msHotel;

Hotel::Hotel(string name, string city, string country) {
	this->name = name;
	this->city = city;
	this->country = country;
}

Hotel::Hotel() {
	this->name = "";
	this->city = "";
	this->country = "";
}

Hotel::~Hotel() {
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

void Hotel::addGuest(Guest guest) {
	unique_ptr<Guest> guestPtr = make_unique<Guest>(move(guest));
	this->guests.push_back(move(guestPtr));
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

vector<unique_ptr<Guest>> Hotel::getGuests() {
	return move(this->guests);
}

//vector<Guest*> Hotel::getGuests() {
//	return this->guests;
//}

void Hotel::addNormalRoom(int number, int size, bool isAvailable) {
	fmHotel.setFilename("rooms.txt");
	int theId = fmHotel.getLastId() + 1;
	rooms.push_back(make_unique<NormalRoom>(theId, number, size, isAvailable));
	//rooms.push_back(new NormalRoom(theId, number, size, isAvailable));
}

void Hotel::addVipRoom(int number, int size, bool isAvailable) {
	fmHotel.setFilename("rooms.txt");
	int theId = fmHotel.getLastId() + 1;
	rooms.push_back(make_unique<VipRoom>(theId, number, size, isAvailable));
}


void Hotel::showRooms() {
	for (int i = 0; i < rooms.size(); i++) {
		cout << rooms[i]->getRoomInfo() << endl;
		/*NormalRoom* normalr = dynamic_cast<NormalRoom*>(&rooms[i]);
		VipRoom* vipr = dynamic_cast<VipRoom*>(&rooms[i]);
		Spa* spar = dynamic_cast<Spa*>(&rooms[i]);

		if (normalr) {
			string theAvailibility = to_string(rooms[i].getIsAvailable()) = "1" ? "available" : "is not available";
			cout << "The room number is: " + to_string(rooms[i].getRoomNum()) + " and the room is " + theAvailibility + ".\n";
		} else if(vipr){
			string theAvailibility = to_string(rooms[i].getIsAvailable()) = "1" ? "available" : "is not available";
			cout << "The room number is: " + to_string(rooms[i].getRoomNum()) + " and the room is " + theAvailibility + ".\n";
		} else if(spar){
			string theAvailibility = to_string(rooms[i].getIsAvailable()) = "1" ? "available" : "is not available";
			cout << "The room number is: " + to_string(rooms[i].getRoomNum()) + " and the room is " + theAvailibility + ".\n";
		} */
	}

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