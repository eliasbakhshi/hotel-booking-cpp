#include "Headers.h"

void menu() {
	string yesOrNo = "N";
	cout << "------------------------------" << endl;
	cout << "Welcome to Hotel California !" << endl;
	cout << "------------------------------\n" << endl;

	cout << "Would you like to book a room? (Y/N)" << endl;
	cin >> yesOrNo;
	 
	if (yesOrNo == "Y" || yesOrNo == "y") {
		exit(0);
	}

	MessageBoxW(NULL, L"Hello, WinAPI!", L"MessageBox Example", MB_OK | MB_ICONINFORMATION);

}

int main() {

	menu();

	return 0;
}