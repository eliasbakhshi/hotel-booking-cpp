#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace std;

// strcuts
struct Reservation {
	int id, roomId, optionId;
};
