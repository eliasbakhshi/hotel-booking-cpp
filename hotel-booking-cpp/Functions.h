#pragma once
#include "Headers.h"
#include "Guest.h"

string bookingNumGenerator();
void registerGuest(Guest& guest);
int showHotels();
void showRooms(int hotelId);
void menu(Guest& guest);