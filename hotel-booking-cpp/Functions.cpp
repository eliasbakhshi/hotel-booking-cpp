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
	const char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const int numCharacters = 8;

	srand(time(0));
	string randomString;

	for (int i = 0; i < 8; ++i) {
		int randomIndex = rand() % numCharacters;
		randomString += characters;
	}
	return randomString;
}
void registerGuest(Guest& guest) {
	fmFunc.setFilename("guests.txt");
	guest.setId(fmFunc.getLastId() + 1);
	guest.setFirstName(miFunc.get_string("First name: "));
	guest.setLastName(miFunc.get_string("nLast name: "));
	guest.setEmail(miFunc.get_string("Email address: "));
	guest.setPhone(miFunc.get_string("Phone number: "));
	// Save it in the database.
	string info = "\n" + to_string(guest.getId()) + "|" + guest.getFirstName() + "|" +
		guest.getLastName() + "|" + guest.getEmail() + "|" + guest.getPhone();
	fmFunc.insert(info);
}
void getInfo() {
	Guest guest("", "", "", "", "");
	string firstName, lastName, mailAddr, phoneNum;
	string bookingNum = bookingNumGenerator();

	ManageString ms;

	cout << "First name: "; cin >> firstName;
	guest.setFirstName(firstName);

	cout << "\nLast name: "; cin >> lastName;
	guest.setLastName(lastName);

	cout << "\nEmail address: "; cin >> mailAddr;
	guest.setEmail(mailAddr);

	cout << "\nPhone number: "; cin >> phoneNum;
	guest.setPhone(phoneNum);

	guest.setBookingNum(bookingNum);
	cout << bookingNum << endl;

	/*string test = ms.guestToS(guest);
	cout << test << endl;*/
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
	vector<string> romms = fmFunc.selectAllByIndex(to_string(hotelId), 4);
	for (int i = 0; i < romms.size(); i++) {
		vector<string> line = msFunc.split(romms[i], "|");
		cout << line[0] << ") Number: " << line[1] << ", floor: " << line[2] << ", size: " << line[3] << "\n";
	}
}

void showLogin(Guest& guest) {
	string email;

	fmFunc.setFilename("guests.txt");
	email = miFunc.get_string("Please enter your email: ");
	vector<string> theGuest = fmFunc.selectByIndex(email, 3);
	if (theGuest.size() > 3 && email == theGuest[3]) {
		isLoggedIn = true;
		guest.setId(stoi(theGuest[0]));
		guest.setFirstName(theGuest[1]);
		guest.setLastName(theGuest[2]);
		guest.setEmail(theGuest[3]);
		guest.setPhone(theGuest[4]);
		system("cls");
		menu(guest);
	} else {
		cout << "\nThis email is not correct.";
		showLogin(guest);
	}
}

void menu(Guest& guest) {

	string menuOption = "";

	cout << "------------------------" << endl;
	cout << "Welcome to Hotel Booker!" << endl;
	cout << "------------------------\n" << endl;

	cout << "Please choose an option: " << endl;
	cout << "1) Book hotel" << endl;
	cout << "2) Register" << endl;
	cout << "3) Login" << endl;
	cout << "q) Quit" << endl;
	cout << "--> "; cin >> menuOption; cin.ignore();
	system("cls");

	if (menuOption == "1") {
		Reservation reservation;
		cout << "Welcome " + guest.getFirstName() << "!\n" << endl;

		int normalOrVip, menuChoise;
		showHotels();
		menuChoise = miFunc.get_int("Please choose the hotel of your choice: ");
		system("cls");
		showRooms(menuChoise);
		menuChoise = miFunc.get_int("Choose the rooms that you want: ");
		reservation.roomId = menuChoise;
		system("cls");
		cout << "1) Normal: Breakfast included" << endl;
		cout << "2) VIP: Breakfast and dinner included + Access to Spa and Swimming pool" << endl;
		menuChoise = miFunc.get_int("Choose the package of your choice: ");
		reservation.optionId = menuChoise;
		// Guest will be navigated to the registration if guest is not registered.
		if (guest.getEmail() == "") {
			// Redirect to reservation 
			cout << "Perfect! You will be redirected to the sign-up page in no time.\nPlease be patient...";
			Sleep(1000);
			system("cls");
			registerGuest(guest);
		}
		// Redirect to reservation page
		cout << "Perfect! You will be redirected to the confirmation page in no time.\nPlease be patient...";
		Sleep(1000);
		system("cls");
		fmFunc.setFilename("reservations.txt");
		reservation.id = fmFunc.getLastId() + 1;
		// Save to reservation table
		string theReservation = "\n" + to_string(reservation.id) + "|" + to_string(guest.getId()) + "|" + to_string(reservation.roomId) + "|" + to_string(reservation.optionId);
		fmFunc.insert(theReservation);
		// Show the reservation info
		cout << "You have booked a room in hotel ";

	}

	else if (menuOption == "2") {
		getInfo();
	}

	else if (menuOption == "3") {
		string email;

		fmFunc.setFilename("guests.txt");
		email = miFunc.get_string("Please enter your email: ");
		vector<string> theGuest = fmFunc.selectByIndex(email, 3);
		if (theGuest.size() > 3 && email == theGuest[3]) {
			isLoggedIn = true;
			guest.setId(stoi(theGuest[0]));
			guest.setFirstName(theGuest[1]);
			guest.setLastName(theGuest[2]);
			guest.setEmail(theGuest[3]);
			guest.setPhone(theGuest[4]);
			system("cls");
			menu(guest);
		} else {
			cout << "\nThis email is not correct.";
			showLogin(guest);
		}
	}

	else if (menuOption == "q") {
		MessageBoxW(NULL, L"Welcome back later!", L"Fine!", MB_OK | MB_ICONINFORMATION);
		exit(0);
	}

	else {
		MessageBoxW(NULL, L"Please double check your input", L"Error!", MB_OK | MB_ICONERROR);
	}
}

void test() {

	//FileManager fm("guests.txt");
	//ManageString ms;
	//string tt = "ölijl ök kjpoij";
	//vector<string> test = ms.split(tt, " ");
	//for (int i = 0; i < test.size(); i++) {
	//	cout << test[i] << endl;
	//}

	//Guest g1("ljgmail221.com");
	//Guest g2("hhhggfgfgrerer.com");
	//int id = fm.insert(ms.guestToS(g1));
	//cout << "the id. " << id << endl;
	//bool deleted = fm.remove(8);
	//bool updated = fm.update(13, ms.guestToS(g2));
	//cout << deleted;
	//vector<string> test2 = fm.select(9);
	//for (int i = 0; i < test2.size(); i++) {
	//	cout << test2[i] << endl;
	//}

	//cout << fm.getLastId();
	//cout << fm.countRows();
	//cout << fm.remove(1);
}
