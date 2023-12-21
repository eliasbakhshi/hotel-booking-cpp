#include "Headers.h"
#include "Functions.h"
#include "Guest.h"
#include "ManageInputs.h"
#include "FileManager.h"


int main() {
	FileManager fm("guests.txt");
	ManageString ms;
	string tt = "ölijl,ök,kjpoij";
	vector<string> test = ms.split(tt, ",");
	for (int i = 0; i < test.size(); i++) {
	cout << test[i] << endl;
	}

	Guest g1("ljgmail221.com");
	fm.insert(g1);

	//cout << fm.getLastId();
	//cout << fm.countRows();
	//cout << fm.remove(1);
	menu();


	return 0;
}