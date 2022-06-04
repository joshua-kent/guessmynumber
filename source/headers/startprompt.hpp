#ifndef START_PROMPT_H
#define START_PROMPT_H

#include <iostream> // cout
#include <cctype> // tolower
#include <sstream> // stringstream
#include <string> // string

#include "query.hpp"
#include "misc.hpp"
#include "version.hpp"


// user selection when the program starts
std::string start() {
    std::stringstream welcome_string;
    welcome_string << "Welcome to Guess My Number, version " << GMN_VERSION;

    Query StartQuery(welcome_string.str(),
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
    StartQuery.Say();
    return StartQuery.answer;
}

#endif