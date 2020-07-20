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
#include "headers/misc.hpp"


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
            help();
            return main();
        case 3: // Version
            misc::clear();
            std::cout << "Guess My Number " << GMN_VERSION << std::endl;
            std::cout << "Last updated " << UPDATE_DATE << std::endl;
            std::cout << "\nWritten by " << GMN_AUTHOR << std::endl;
            std::cout << "See the official repository page at: "
                      << "https://github.com/joshua-kent/guessmynumber"
                      << std::endl;
            
            misc::petc(); // press enter to continue
            return main();
        case 4: // Exit
            return 0;
        default: // If answer is none of above
            return main();
    }
}