#include <sstream>
#include "include/query.hpp"
#include "include/version.hpp"
#include "include/helpprompt.hpp"
#include "include/exitprompt.hpp"
#include "include/misc.hpp"
#include "include/difficulty.hpp"

int start() {
    misc::clear();

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
    
    // decide what to do based on the user's response
    if (StartQuery.answer == "Play") {
        return difficultyPrompt();
    } else if (StartQuery.answer == "Help") {
        help();
        return start();
    } else if (StartQuery.answer == "Version") {
        version();
        return start();
    } else if (StartQuery.answer == "Quit" || StartQuery.answer == "exit") {
        int confirmExit = exitprompt();
        if (confirmExit) {
            return 0;
        } else {
            return start();
        }
    } else {
        return start();
    }
}