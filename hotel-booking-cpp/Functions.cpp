#include "Functions.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "ManageString.h"
#include "FileManager.h"

bool isLoggedIn = false;


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
	FileManager fm;
	ManageString ms;
	fm.setFilename("hotels.txt");
	vector<string> hotels = fm.selectAll();
	for (int i = 0; i < hotels.size(); i++) {
		vector<string> line = ms.split(hotels[i], "|");
		cout << line[0] << ") " << line[1] << " - " << line[2] << ", " << line[3] << "\n";
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

	cout << "Welcome " + guest.getFirstName() << "!\n" << endl;

	if (menuOption == "1") {

		int whichHotel;
		int normalOrVip;

		showHotels();
		cout << "\nPlease choose the hotel of your choice: ";
		cin >> whichHotel; cin.ignore();

		cout << "\nChoose the package of your choice: " << endl;
		cout << "1) Normal: Breakfast included" << endl;
		cout << "2) VIP: Breakfast and dinner included + Access to Spa and Swimming pool" << endl;
		cin >> normalOrVip; cin.ignore();

		cout << "Perfect! You will be redirected to the sign-up page in no time.\nPlease be patient...";
		Sleep(5000);
		system("cls");
		getInfo();

	}

	else if (menuOption == "2") {
		getInfo();
	}

	else if (menuOption == "3") {
		string email;
		FileManager fm;
		ManageString ms;

		cout << "Enter you mail address: "; getline(cin, email);
		fm.setFilename("guests.txt");
		vector<string> theGuest = fm.selectByIndex(email, 3);
		if (email == theGuest[3]) {
			isLoggedIn = true;
			guest.setId(stoi(theGuest[0]));
			guest.setFirstName(theGuest[1]);
			guest.setLastName(theGuest[2]);
			guest.setEmail(theGuest[3]);
			guest.setPhone(theGuest[4]);
			system("cls");
			menu(guest);
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
