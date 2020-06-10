#include <iostream> // cout
#include <cctype> // tolower
#include <sstream> // stringstream
#include <string> // string

#include "version.hpp"
#ifndef MISC_H
#include "misc.hpp"
#endif

using namespace std;

// user selection when the program starts
int start() {
    stringstream welcome_string;
    welcome_string << "Welcome to Guess My Number, version " << GMN_VERSION;

    misc::query start_query;
    int ans = start_query.new_query(welcome_string.str(),
                                    {
                                        "Play",
                                        "Help",
                                        "Version",
                                        "Quit"
                                    },
                                    {
                                        "play",
                                        "help",
                                        "version",
                                        "quit"
                                    });
    
    return ans;
}