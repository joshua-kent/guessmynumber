#include <iostream> // cout
#include <cctype> // tolower
#include <sstream> // stringstream
#include <string> // string

#include "include/query.hpp"
#include "include/misc.hpp"
#include "include/version.hpp"


// user selection when the program starts
std::string start() {
    std::stringstream welcome_string;
    welcome_string << "Welcome to Guess My Number, version " << VERSION;

    Query StartQuery(welcome_string.str(),
                    {
                        "Play",
                        "Help",
                        "Version",
                        "Quit"
                    });
    StartQuery.Say(true, true, true);
    return StartQuery.answer;
}