#pragma once
#include "Headers.h"
#include "Guest.h"

string bookingNumGenerator();
void registerGuest(Guest& guest);
void showHotels();
void showRooms(int hotelId);
void menu(Guest& guest);