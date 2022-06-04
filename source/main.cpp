/*
---------------------------------
Guess My Number (console version)
---------------------------------
 */

#include <iostream> // cout
#include <cstdlib> // system

#include "headers/play.hpp"
#include "headers/startprompt.hpp"
#include "headers/helpprompt.hpp"
#include "headers/exitprompt.hpp"
#include "headers/version.hpp"
#include "headers/misc.hpp"


int main() {
    misc::clear();

    std::string startOption = start(); // initiate start menu, get response

    // decide what to do based on the user's response
    if (startOption == "Play") {
        return play();
    } else if (startOption == "Help") {
        help();
        return main();
    } else if (startOption == "Version") {
        version();
        return main();
    } else if (startOption == "Quit" || startOption == "exit") {
        int confirmExit = exit();
        if (confirmExit) {
            return 0;
        } else {
            return main();
        }
    } else {
        return main();
    }
    
    return 0;
}