/*
---------------------------------
Guess My Number (console version)
---------------------------------
 */

#include <iostream> // cout
#include <cstdlib> // system

#include "headers/startprompt.hpp"
#include "headers/helpprompt.hpp"
#include "headers/play.hpp"
#include "headers/version.hpp"


int main() {
    // check Operating System
    #ifndef _WIN64
    #ifndef __linux__
    std::cout << "This program only runs on Windows 64-bit and Linux." << std::endl;
    return 0;
    #endif
    #endif

    misc::clear();

    int ans = start(); // initiate start menu, get response

    // decide what to do based on the user's response
    switch (ans) {
        case 1: // Play
            return play();
        case 2: // Help
            return help();
        case 3: // Version
            std::cout << GMN_VERSION << std::endl;
            return main();
        case 4: // Exit
            return 0;
        default: // If answer is none of above
            return main();
    }
}