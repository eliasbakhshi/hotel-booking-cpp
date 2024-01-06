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

int showHotels() {
	fmFunc.setFilename("hotels.txt");
	vector<string> hotels = fmFunc.selectAll();
	for (int i = 0; i < hotels.size(); i++) {
		vector<string> line = msFunc.split(hotels[i], "|");
		cout << line[0] << ") " << line[1] << " - " << line[2] << ", " << line[3] << "\n";
	}
	return static_cast<int>(hotels.size());
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
		Hotel hotel;
		// Set guest
		hotel.addGuest(guest);

		// Show menu.
		cout << "------------------------" << endl;
		cout << "Welcome to Hotel Booker!" << endl;
		cout << "------------------------\n" << endl;

		cout << "Please choose an option: " << endl;
		cout << "1) Book hotel" << endl;
		cout << "2) Register" << endl;
		cout << "3) Login" << endl;
		//if (guest.getEmail() != "")
		if (isLoggedIn == true)
			cout << "4) logout" << endl;
		cout << "q) Quit" << endl;
		menuOption = miFunc.get_string("\n--> ");
		system("cls");

		if (menuOption == "1") {
			Reservation reservation;
			vector<string> theHotel, theRoom, theOption;
			VipRoom viproom;
			NormalRoom normalroom;
			int hotelNum = 0, roomNum = 0, totalHotels = 0, totalRooms = 0;
			string roomType;

			cout << "Welcome " + guest.getFirstName() << "!\n" << endl;

			totalHotels = showHotels();
			hotelNum = miFunc.get_int("\n\nPlease choose the hotel of your choice: ", 1, totalHotels);
			system("cls");
			hotel.update(hotelNum);
			totalRooms = hotel.showRooms();
			roomNum = miFunc.get_int("\n\nChoose the rooms that you want: ", 1, totalRooms);
			reservation.roomId = roomNum;
			// show options according to rooms type
			if (roomNum == 1) {
				reservation.options = normalroom.getMinibarContent();
				roomType = "Normal";
			}
			else if (roomNum == 2) {
				reservation.options = viproom.getMeals();
				roomType = "VIP";
			}
			// Get the dates
			theRoom = fmFunc.selectByIndex(to_string(roomNum), 0, "rooms.txt");
			system("cls");
			reservation.dateIn = miFunc.get_string("Check in date (yyyy/mm/dd): ");
			reservation.dateOut = miFunc.get_string("Check out date (yyyy/mm/dd): ");
			// Guest will be navigated to the registration if guest is not registered.
			if (guest.getEmail() == "") {
				cout << "Perfect! You will be redirected to the sign-up page in no time.\nPlease be patient...";
				Sleep(3000);
				system("cls");
				registerGuest(guest);
				hotel.addGuest(guest);
			}
			// Redirect to reservation page
			system("cls");
			cout << "Perfect! You will be redirected to the confirmation page in no time.\nPlease be patient...";
			Sleep(3000);
			reservation.id = fmFunc.getLastId("reservations.txt") + 1;
			// Save to reservation table
			string theReservation = "\n" + to_string(reservation.id) + "|" + to_string(guest.getId()) + "|" + to_string(reservation.roomId) + "|" + reservation.options + "|" + reservation.dateIn + "|" + reservation.dateOut;
			fmFunc.insert(theReservation, "reservations.txt");
			// Get the hotel info
			theHotel = fmFunc.selectByIndex(to_string(hotelNum), 0, "hotels.txt");
			system("cls");

			// Show the reservation info in the confirmation page.
			cout << "<--- Your booking information --->\n";
			cout << "Type: " << roomType << " room\n";
			cout << "Hotel: " << theHotel[1] << " in " << theHotel[2] << ", " << theHotel[3] << theHotel[4] << endl;
			if (roomType == "VIP" && reservation.options != "") {
				viproom.showMeals();
			} else if (roomType == "VIP" && reservation.options != "") {
				normalroom.showMinibarContent();
			}
			guest.setBookingNum(bookingNumGenerator());
			cout << "Booking number is: " + guest.getBookingNum() + ". Do not lose it!\n";

			cout << "\nPress enter to go to the menu...\n";
			getchar();
			system("cls");
		}

		else if (menuOption == "2") {

			// if email already exists, deny it !! read from text file
			Guest guest;
			registerGuest(guest);
			isLoggedIn = true;
			cout << "\nYou have been registered.\ You will be redirected to the menu soon.";
			Sleep(3000);
			system("cls");
		}

		else if (menuOption == "3") {
			string email, password;
			vector<string> theGuest;
			int tried = 0, tryTimes = 3;

			while (tried < tryTimes) {
				email = miFunc.get_string("Please enter your email: ");
				password = miFunc.get_string("Please enter your password: ");
				theGuest = fmFunc.selectByIndex(email, 3, "guests.txt");
				if (theGuest.size() > 2 && email == theGuest[3] && theGuest[5] == password) {
					isLoggedIn = true;
					guest.setFirstName(theGuest[1]);
					hotel.updateGuest(stoi(theGuest[0]), theGuest[1], theGuest[2], theGuest[3], theGuest[4], theGuest[5]);
					cout << "You are logged in. You are going to be redirected to the menu.\nPlease wait...";
					Sleep(3000);
					system("cls");
					menu(guest);
					break;
				}
				else {
					system("cls");
					tried++;
					cout << "Incorrect email or password. You have " << tryTimes - tried << " tries remaining. Please try again.\n\n";
				}
			}
			cout << "You could not log in. You are going to be redirected to the menu.\nPlease wait...";
			Sleep(3000);
			system("cls");
			menu(guest);
		}
		//// Update the info
		//if (theGuest.size() > 2 && theGuest[0] != "false") {
		//	isLoggedIn = true;
		//	guest.setId(stoi(theGuest[0]));
		//	guest.setFirstName(theGuest[1]);
		//	guest.setLastName(theGuest[2]);
		//	guest.setEmail(theGuest[3]);
		//	guest.setPhone(theGuest[4]);
		//	cout << "You are logged in. You are going to be redirected to the menu.\nPlease wait...";
		//	Sleep(3000);
		//}
		//else {
		//	cout << "You could not log in. You are going to be redirected to the menu.\nPlease wait...";
		//	Sleep(3000);
		//}
		//system("cls");
		//menu(guest);

		else if (menuOption == "4") {
			if (isLoggedIn == true) {
				//Hotel hotel;
				/*hotel.getGuests()
				int id = guest.getId();
				hotel.removeGuest(id);*/
				isLoggedIn = false;
				guest.setFirstName("Guest user");
				cout << "\nLogged out successfully. See you later!" << endl;
				Sleep(3000);
				system("cls");
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
