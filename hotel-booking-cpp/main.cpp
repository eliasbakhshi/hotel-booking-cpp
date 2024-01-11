#include "Headers.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "FileManager.h"
#include "Functions.h"
#include "NormalRoom.h"
#include "VipRoom.h"


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Hotel hotel;
	Guest guest;
	bool isLoggedIn = false;
	string menuOption = "";
	hotel.addGuest(guest);

	FileManager fmFunc;
	ManageInputs miFunc;
	ManageString msFunc;

	while (true) {
		// Show menu.
		cout << "------------------------" << endl;
		cout << "Welcome to Hotel Booker!" << endl;
		cout << "------------------------\n" << endl;

		cout << "Please choose an option: " << endl;
		cout << "b) Book hotel" << endl;
		if (!isLoggedIn) {
			cout << "r) Register" << endl;
			cout << "l) Login" << endl;
		} else cout << "lo) logout" << endl;
		cout << "q) Quit" << endl;
		menuOption = msFunc.toLower(miFunc.get_string("\n--> "));
		system("cls");

		if (menuOption == "b") {
			Reservation reservation;
			vector<string> theHotel, theRoom, theOption;
			VipRoom viproom;
			NormalRoom normalroom;
			int hotelNum = 0, roomNum = 0, totalHotels = 0, totalRooms = 0;
			string roomType;

			cout << "Welcome " + guest.getFirstName() << "!\n" << endl;
			// Show all hotels.
			totalHotels = hotel.showHotels();
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
			} else if (roomNum == 2) {
				reservation.options = viproom.getMeals();
				roomType = "VIP";
			}
			// Get the dates
			theRoom = fmFunc.selectByIndex(to_string(roomNum), 0, "rooms.txt");
			system("cls");
			reservation.dateIn = miFunc.get_string("Check in date (yyyy/mm/dd): ");
			reservation.dateOut = miFunc.get_string("Check out date (yyyy/mm/dd): ");
			// Guest will be navigated to the registration if guest is not registered.
			if (isLoggedIn == false) {
				cout << "Perfect! You will be redirected to the sign-up page in no time.\nPlease be patient...";
				Sleep(3000);
				system("cls");
				hotel.registerGuest(guest);
				hotel.addGuest(guest);
				isLoggedIn = true;
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
			} else if (roomType == "Normal" && reservation.options != "") {
				normalroom.showMinibarContent();
			}
			guest.setBookingNum(hotel.bookingNumGenerator());
			cout << "Booking number is: " + guest.getBookingNum() + ". Do not lose it!\n";

			cout << "\nPress enter to go to the menu...\n";
			char returned = getchar();
			system("cls");
		}

		else if (menuOption == "r" && !isLoggedIn) { // Register
			Guest guest;
			hotel.registerGuest(guest);
			isLoggedIn = true;
			cout << "\nYou have been registered.\nYou will be redirected to the menu soon.";
			Sleep(3000);
			system("cls");
		}

		else if (menuOption == "l" && !isLoggedIn) { // Login
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
					break;
				} else {
					system("cls");
					tried++;
					cout << "Incorrect email or password. You have " << tryTimes - tried << " tries remaining. Please try again.\n\n";
				}
			}
			if (!isLoggedIn) {
				cout << "You could not log in. You are going to be redirected to the menu.\nPlease wait...";
				Sleep(3000);
				system("cls");
				continue;
			}
		} 
		else if (menuOption == "lo" && isLoggedIn) {
			if (isLoggedIn == true) {
				isLoggedIn = false;
				hotel.clearGuestVector();
				guest.setFirstName("Guest user");
				cout << "\nLogged out successfully. See you later!" << endl;
				Sleep(3000);
				system("cls");
			} else { cout << "You're not logged in!"; }
		} else if (menuOption == "q") {
			MessageBoxW(NULL, L"Welcome back later!", L"Fine!", MB_OK | MB_ICONINFORMATION);
			break;
		} else {
			MessageBoxW(NULL, L"Please double check your input", L"Error!", MB_OK | MB_ICONERROR);
		}
	}

	return 0;
}