#include "Headers.h"
#include "Functions.h"
#include "Guest.h"
#include "ManageString.h"
#include "ManageInputs.h"
#include "FileManager.h"

bool isLoggedIn = false;

FileManager fmFunc;
ManageString msFunc;
ManageInputs miFunc;

string bookingNumGenerator() {
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

void registerGuest(Guest& guest) {
	fmFunc.setFilename("guests.txt");
	guest.setId(fmFunc.getLastId() + 1);
	guest.setFirstName(miFunc.get_string("First name: "));
	guest.setLastName(miFunc.get_string("Last name: "));
	guest.setEmail(miFunc.get_string("Email address: "));
	guest.setPassword(miFunc.get_string("Password: "));
	guest.setPhone(miFunc.get_string("Phone number: "));
	// Save it in the database.
	string info = "\n" + to_string(guest.getId()) + "|" + guest.getFirstName() + "|" +
		guest.getLastName() + "|" + guest.getEmail() + "|" + guest.getPassword() + "|" + guest.getPhone();
	fmFunc.insert(info);
}

void showHotels() {
	fmFunc.setFilename("hotels.txt");
	vector<string> hotels = fmFunc.selectAll();
	for (int i = 0; i < hotels.size(); i++) {
		vector<string> line = msFunc.split(hotels[i], "|");
		cout << line[0] << ") " << line[1] << " - " << line[2] << ", " << line[3] << "\n";
	}
}

void showRooms(int hotelId) {
	fmFunc.setFilename("rooms.txt");
	vector<string> rooms = fmFunc.selectAllByIndex(to_string(hotelId), 4);
	for (int i = 0; i < rooms.size(); i++) {
		vector<string> line = msFunc.split(rooms[i], "|");
		cout << line[0] << ") Type: " << line[5] << ", Number: " << line[1] << ", floor: " << line[2] << ", size: " << line[3] << "\n";
	}
}

void menu(Guest& guest) {
	while (true) {
		// Outside of the numbers
		string menuOption = "";

		cout << "------------------------" << endl;
		cout << "Welcome to Hotel Booker!" << endl;
		cout << "------------------------\n" << endl;

		cout << "Please choose an option: " << endl;
		cout << "1) Book hotel" << endl;
		cout << "2) Register" << endl;
		cout << "3) Login" << endl;
		if (guest.getEmail() != "")
			cout << "3) logout" << endl;
		cout << "q) Quit" << endl;
		cout << "\n--> "; cin >> menuOption; cin.ignore();
		system("cls");

		if (menuOption == "1") {
			cout << "Welcome " + guest.getFirstName() << "!\n" << endl;
			if (menuOption == "1") {
				Reservation reservation;
				vector<string> theHotel, theRoom, options, theOption;
				vector<vector<string>> allOptions;
				VipRoom viproom;
				string optionNums, optionNum, comma;
				NormalRoom normalroom;
				int hotelNum, roomNum;
				cout << "Welcome " + guest.getFirstName() << "!\n" << endl;

				showHotels();
				hotelNum = miFunc.get_int("\n\nPlease choose the hotel of your choice: ");
				system("cls");
				showRooms(hotelNum);
				roomNum = miFunc.get_int("\n\nChoose the rooms that you want: ");
				reservation.roomId = roomNum;
				system("cls");
				// show options according to rooms type
				theRoom = fmFunc.selectByIndex(to_string(roomNum), 0, "rooms.txt");
				if (theRoom[5] == "normal") {
					options = fmFunc.selectAllByIndex("normal", 1, "roomOptions.txt");
				}
				else if (theRoom[5] == "vip") {
					options = fmFunc.selectAllByIndex("vip", 1, "roomOptions.txt");
				}
				while (true) {
					cout << "0) None" << ".\n";
					for (int i = 0; i < options.size(); i++) {
						allOptions.push_back(msFunc.split(options[i], "|"));
						cout << i + 1 << ") " << allOptions[i][2] << ".\n";
					}
					cout << "d) Done.";
					optionNum = miFunc.get_string("\n\nChoose the addon option for the room: ");
					if (optionNum != "0" && msFunc.is_number(optionNum)) {
						optionNums += comma + allOptions[stoi(optionNum) - 1][0];
						comma = ",";
					}
					else if (optionNum == "d") {
						break;
					}
					reservation.options = stoi(allOptions[stoi(optionNum) - 1][0]);
				}
				// Get the dates
				system("cls");
				reservation.dateIn = miFunc.get_string("Check in date (yyyy/mm/dd): ");
				reservation.dateOut = miFunc.get_string("Check out date (yyyy/mm/dd): ");
				// Guest will be navigated to the registration if guest is not registered.
				if (guest.getEmail() == "") {
					cout << "Perfect! You will be redirected to the sign-up page in no time.\nPlease be patient...";
					Sleep(1000);
					system("cls");
					registerGuest(guest);
				}
				// Redirect to reservation page
				system("cls");
				cout << "Perfect! You will be redirected to the confirmation page in no time.\nPlease be patient...";
				Sleep(1000);
				reservation.id = fmFunc.getLastId("reservations.txt") + 1;
				// Save to reservation table
				string theReservation = "\n" + to_string(reservation.id) + "|" + to_string(guest.getId()) + "|" + to_string(reservation.roomId) + "|" + reservation.options + "|" + reservation.dateIn + "|" + reservation.dateOut;
				fmFunc.insert(theReservation, "reservations.txt");
				// Get the hotel info
				theHotel = fmFunc.selectByIndex(to_string(hotelNum), 0, "hotels.txt");
				system("cls");

				// Show the reservation info in the confirmation page.
				cout << "Your booking information:\n";
				cout << "Type: " << theRoom[5] << " room\n";
				cout << "Hotel: " << theHotel[1] << " in " << theHotel[2] << ", " << theHotel[3] << endl;
				cout << "Address: " << theHotel[4] << endl;
				//cout << "Addons: " << viproom.showMeals() << endl;
				//cout << "Addons: " << allOptions[optionNum - 1][2] << " on your booking.\n";
				if (theRoom[5] == "vip") {
					Spa spa;
					spa.setIsVip(true);
					cout << "Your personal Spa entry code is: <" + to_string(spa.generateCustomEntryCode())
						+ "> Do not lose it!\n";
				}
				guest.setBookingNum(bookingNumGenerator());
				cout << "Your booking number is: " + guest.getBookingNum() + ". Do not lose it!\n";
			}

			else if (menuOption == "2") {
				Guest guest;
				registerGuest(guest);
				isLoggedIn = true;
			}

			else if (menuOption == "3") {
				string email, password;
				vector<string> theGuest = { "false" };
				bool isLoggedIn = false;
				int tried = 0, tryTimes = 3;
				while (tried < tryTimes) {
					email = miFunc.get_string("Please enter your email: ");
					password = miFunc.get_string("Please enter your password: ");

					theGuest = fmFunc.selectByIndex(email, 3, "guests.txt");
					if (theGuest.size() > 2 && email == theGuest[3] && theGuest[5] == password) {
						break;
					}
					else if (tried < tryTimes) {
						system("cls");
						tried++;
						cout << "This email and password is not correct. Please try it again. You have " << tryTimes - tried << " try remains. \n\n";
					}
				}
				// Update the info
				if (theGuest.size() > 2 && theGuest[0] != "false") {
					isLoggedIn = true;
					guest.setId(stoi(theGuest[0]));
					guest.setFirstName(theGuest[1]);
					guest.setLastName(theGuest[2]);
					guest.setEmail(theGuest[3]);
					guest.setPhone(theGuest[4]);
					cout << "You are logged in. You are going to be redirected to the menu.\nPlease wait...";
					Sleep(1000);
				}
				else {
					cout << "You could not log in. You are going to be redirected to the menu.\nPlease wait...";
					Sleep(1000);
				}
				system("cls");
				menu(guest);
			}
			else if (menuOption == "4" && guest.getEmail() != "") {
				if (isLoggedIn == true) {
					Hotel hotel;
					int id = guest.getId();
					hotel.removeGuest(id);
					isLoggedIn = false;
				}
				else { cout << "You're not logged in!"; }
			}
			else if (menuOption == "q") {
				MessageBoxW(NULL, L"Welcome back later!", L"Fine!", MB_OK | MB_ICONINFORMATION);
				break;
			}
			else {
				MessageBoxW(NULL, L"Please double check your input", L"Error!", MB_OK | MB_ICONERROR);
			}
		}
	}
}
