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
    if (startOption == "play") {
        return play();
    } else if (startOption == "help") {
        help();
        return main();
    } else if (startOption == "version") {
        version();
        return main();
    } else if (startOption == "quit" || startOption == "exit") {
        exit();
        return 0;
    } else {
        return main();
    }
    
    return 0;
}