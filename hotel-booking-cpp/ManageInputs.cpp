#pragma once
#include "ManageInputs.h"

ManageInputs::ManageInputs() {}

ManageInputs::~ManageInputs() {}

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

int ManageInputs::get_int(string message, int times) {
    int output = 0;
    if (times == 0) {
        string theInput;
        cout << message;
        getline(cin, theInput);

        while (!is_number(theInput)) {
            cout << "Please enter a valid number.\n";
            cout << message;
            getline(cin, theInput);
            output = stoi(theInput);
        }
    }
    else {
        for (int i = 0; i < times; i++) {
            string theInput;
            cout << message;
            getline(cin, theInput);

            while (!is_number(theInput)) {
                cout << "Please enter a valid number.\n";
                cout << message;
                getline(cin, theInput);
                output = stoi(theInput);
            }
        }
    }
    return output;
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