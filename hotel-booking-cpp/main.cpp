#include "Headers.h"
#include "Functions.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "FileManager.h"


int main() {
	FileManager fm("guests.txt");
	Guest g1("ljgmail221.com");

	fm.insert(g1);
	cout << fm.getLastId();
	menu();


	return 0;
}