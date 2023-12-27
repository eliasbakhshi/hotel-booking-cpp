#include "Functions.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "FileManager.h"

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

int getInfo() {
	bool allGood = false;
	Guest guest;
	string firstName;
	string lastName;
	string mailAddr;
	string phoneNum;
	string bookingNum = bookingNumGenerator();

	cout << "First name: "; cin >> firstName;
	guest.setFirstName(firstName);

	cout << "\nLast name: "; cin >> lastName;
	guest.setLastName(lastName);

	cout << "\nEmail address: "; cin >> mailAddr;
	guest.setEmail(mailAddr);

	cout << "\nPhone number: "; cin >> phoneNum;
	guest.setPhone(phoneNum);

	/*guest.setBookingNum(bookingNum);
	cout << bookingNum << endl;*/

	return 1;
}

void menu() {
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

	if (menuOption == "1") {
		
		string hotels[10];
		int whichHotel;
		int normalOrVip;
		string wantsGarage = "";
		CHAR userName[MAX_PATH];
		DWORD size = sizeof(userName) / sizeof(userName[0]);

		if (GetUserNameA(userName, &size)) {
			cout << "\nWELCOME " << userName << "!\n" << endl;
		}
		hotels[0] = "1) Grand Hotel - Stockholm, Sweden";
		hotels[1] = "2) Hotel California - Zurich, Switzerland";
		hotels[2] = "3) Four Seasons Hotel - Kuala Lumpur, Malaysia";
		hotels[3] = "4) Boston Harbor - Boston, Massachussets, USA";
		hotels[4] = "5) Espinas Palace - Tehran, Iran";
		hotels[5] = "6) Burj al-Arab Jumeirah - Dubai, UAE";
		hotels[6] = "7) Hilton Kyiv - Kyiv, Ukraine";
		hotels[7] = "8) Four Seasons Hotel - Moscow, Russia";
		hotels[8] = "9) Capella - Singapore";
		hotels[9]  = "10) Aman - Tokyo, Japan";

		for (int i = 0; i < 10; i++) {
			cout << hotels[i] << endl;
		}
		cout << "\nPlease choose the hotel of your choice: ";
		cin >> whichHotel; cin.ignore();

		cout << "\nChoose the package of your choice: " << endl;
		cout << "1) Normal: 22 sqm room + Breakfast included" << endl;
		cout << "2) VIP: 43 sqm room + Breakfast and dinner included + Access to Spa and Swimming pool" << endl;
		cin >> normalOrVip; cin.ignore();

		cout << "\nWill you need a parking space? (Y/N) ";
		cin >> wantsGarage; cin.ignore();

		cout << "Perfect! You will be redirected to the sign-up page in no time.\nPlease be patient...";
		Sleep(5000);
		system("cls");
		getInfo();

	}

	else if (menuOption == "2") {

	}

	else if (menuOption == "3") {

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

	FileManager fm("guests.txt");
	ManageString ms;
	string tt = "ölijl ök kjpoij";
	vector<string> test = ms.split(tt, " ");
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << endl;
	}

	Guest g1("ljgmail221.com");
	Guest g2("hhhggfgfgrerer.com");
	int id = fm.insert(ms.guestToS(g1));
	cout << "the id. " << id << endl;
	bool deleted = fm.remove(8);
	bool updated = fm.update(13, ms.guestToS(g2));
	cout << deleted;
	vector<string> test2 = fm.select(9);
	for (int i = 0; i < test2.size(); i++) {
		cout << test2[i] << endl;
	}

	//cout << fm.getLastId();
	//cout << fm.countRows();
	//cout << fm.remove(1);
}
