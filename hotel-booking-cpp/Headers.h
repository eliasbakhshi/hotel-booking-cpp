#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <memory>
#include <stdexcept>
#include <functional>
#include <random>
using namespace std;


// strcuts
struct Reservation {
	int id, roomId, optionId;
	string dateIn, dateOut;
};
