#include "Hotel.h"

FileManager fmHotel;
ManageString msHotel;
ManageInputs miHotel;

Hotel::Hotel(string name, string city, string country) {
	this->name = name;
	this->city = city;
	this->country = country;
}

void Hotel::update(int hotelId) {
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

Hotel::Hotel() {
	this->hotelId = 0;

	this->name = "";
	this->country = "";
	this->city = "";
	this->address = "";
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

int Hotel::showHotels() {
	fmHotel.setFilename("hotels.txt");
	vector<string> hotels = fmHotel.selectAll();
	for (int i = 0; i < hotels.size(); i++) {
		vector<string> line = msHotel.split(hotels[i], "|");
		cout << line[0] << ") " << line[1] << " - " << line[2] << ", " << line[3] << "\n";
	}
	return static_cast<int>(hotels.size());
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
	return static_cast<int>(rooms.size());
}

int Hotel::showOptions(int roomId) {
	NormalRoom* normalr = dynamic_cast<NormalRoom*>(rooms[roomId].get());
	VipRoom* vipr = dynamic_cast<VipRoom*>(rooms[roomId].get());
	if (normalr) {
		normalr->showMinibarContent();
	} else {
		vipr->showMeals();
	}

	return 0;
}

void Hotel::showGuests() const {
	for (const auto& guestPtr : guests) {
		cout << guestPtr->getFirstName() << " " << guestPtr->getLastName() << endl;
	}
}

bool Hotel::clearGuestVector() {
	bool isDeleted = false;

	this->guests.clear();
	isDeleted = true;

	return isDeleted;
}

void Hotel::registerGuest(Guest& guest) {
	fmHotel.setFilename("guests.txt");
	guest.setId(fmHotel.getLastId() + 1);
	guest.setFirstName(miHotel.get_string("First name: "));
	guest.setLastName(miHotel.get_string("Last name: "));
	guest.setEmail(miHotel.get_string("Email address: "));
	guest.setPassword(miHotel.get_string("Password: "));
	guest.setPhone(miHotel.get_string("Phone number: "));
	this->addGuest(guest);
	// Save it in the database.
	string info = "\n" + to_string(guest.getId()) + "|" + guest.getFirstName() + "|" +
		guest.getLastName() + "|" + guest.getEmail() + "|" + guest.getPassword() + "|" + guest.getPhone();
	fmHotel.insert(info);
}

string Hotel::bookingNumGenerator() {
	// Generates a booking number of 8 characters including letters and numbers
	random_device rd;
	mt19937 gen(rd());
	const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	auto randomChar = [&]() -> char {
		uniform_int_distribution<size_t> dis(0, characters.size() - 1);
		return characters[dis(gen)];
		};

	string randomString;
	generate_n(back_inserter(randomString), 8, randomChar);

	return randomString;
}

void Hotel::updateGuest(int id, string firstName, string lastName, string email, string phone, string password) {
	for (const auto& guestPtr : this->guests) {
		if ("Guest user" == guestPtr->getFirstName()) {
			guestPtr->setId(id);
			guestPtr->setFirstName(firstName);
			guestPtr->setLastName(lastName);
			guestPtr->setEmail(email);
			guestPtr->setPhone(phone);
			guestPtr->setPassword(password);
		} else if (email == guestPtr->getEmail()) {
			guestPtr->setId(id);
			guestPtr->setFirstName(firstName);
			guestPtr->setLastName(lastName);
			guestPtr->setEmail(email);
			guestPtr->setPhone(phone);
			guestPtr->setPassword(password);
		}
	}
}
