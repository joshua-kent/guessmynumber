#include <sstream>
#include "query.hpp"
#include "version.hpp"
#include "helpprompt.hpp"
#include "exitprompt.hpp"
#include "misc.hpp"
#include "difficulty.hpp"

int main() {
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
        return main();
    } else if (StartQuery.answer == "Version") {
        version();
        return main();
    } else if (StartQuery.answer == "Quit" || StartQuery.answer == "exit") {
        int confirmExit = exitprompt();
        if (confirmExit) {
            return 0;
        } else {
            return main();
        }
    } else {
        return main();
    }
}