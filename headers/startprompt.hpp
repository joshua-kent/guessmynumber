#include <iostream>
#include <cctype>

#include "version.hpp"

using namespace std;

// user selection when the program starts
string start() {
    cout << "Welcome to Guess My Number, version " << GMN_VERSION << string(2, '\n')
         << "What do you want to do?" << endl << "Options:" << endl
         << "   Play" << endl
         << "   Help" << endl
         << "   Version" << endl
         << "   Quit" << string(2, '\n')
         << ":";
    
    string user_input;
    cin >> user_input;

    for (char &c : user_input) {
        c = tolower(c);
    }

    return user_input;
}