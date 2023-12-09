#pragma once
#include "ManageInputs.h"

string ManageInputs::get_string(string message, bool acceptEmptyString) {
    string theInput;
    cout << message;
    getline(cin, theInput);

    // Use a loop instead of recursion
    while (!acceptEmptyString && theInput.empty()) {
        cout << "Please enter a non-empty string.\n";
        cout << message;
        getline(cin, theInput);
    }
    return theInput;
}

int ManageInputs::get_int(string message) {
    string theInput;
    cout << message;
    getline(cin, theInput);

    while (!is_number(theInput)) {
        cout << "Please enter a valid number.\n";
        cout << message;
        getline(cin, theInput);
    }

    return stoi(theInput);
}

float ManageInputs::get_float(string message) {
    string theInput;
    cout << message;
    getline(cin, theInput);

    while (!is_number(theInput)) {
        cout << "Please enter a valid number.\n";
        cout << message;
        getline(cin, theInput);
    }

    return stof(theInput);
}