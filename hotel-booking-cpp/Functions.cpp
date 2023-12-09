#include "Functions.h"

void menu() {
	string yesOrNo = "G";

	cout << "------------------------" << endl;
	cout << "Welcome to Hotel Booker!" << endl;
	cout << "------------------------\n" << endl;
	cout << "Press <Enter> to start..." << endl;
	getchar();
	cout << "Seems like you want to book a room, is that so? (Y/N)" << endl;
	cin >> yesOrNo; cin.ignore();

	if (yesOrNo == "Y" || yesOrNo == "y") {

		CHAR userName[MAX_PATH];
		DWORD size = sizeof(userName) / sizeof(userName[0]);

		if (GetUserNameA(userName, &size)) {
			cout << "Welcome " << userName << "!" << endl;
		}
	}

	else if (yesOrNo == "N" || yesOrNo == "n") {
		MessageBoxW(NULL, L"Welcome back later!", L"Fine!", MB_OK | MB_ICONINFORMATION);
		exit(0);
	}

	else {
		MessageBoxW(NULL, L"Please double check your input", L"Error!", MB_OK | MB_ICONERROR);
	}
}