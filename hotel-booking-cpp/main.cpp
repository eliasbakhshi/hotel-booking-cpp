#include "Headers.h"
#include "Functions.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "FileManager.h"


int main() {
	FileManager fm;
	Guest g1("ljlökj@gmail.com");

	fm.saveToFile("guests.txt", g1);
	menu();


	return 0;
}