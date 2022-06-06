#include <sstream>
#include <string>

#include "query.hpp"
#include "misc.hpp"
#include "version.hpp"


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