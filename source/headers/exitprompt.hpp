#ifndef EXIT_PROMPT_H
#define EXIT_PROMPT_H


#include <iostream>
#include <string>

#include "misc.hpp"
// TODO: create an actual exit prompt (confirm exit)

int exit() {
    std::string answer;

    misc::clear();

    std::cout << "Are you really sure you want to exit? (Y/N): ";
    std::cin >> answer;
    
    // convert answer to lowercase
    for (char &c : answer) {
        c = tolower(c);
    }

    if (answer == "yes" || answer == "y") {
        return 1; // yes
    } else if (answer == "no" || answer == "n") {
        return 0; // no
    } else {
        return exit(); // ask again
    }
}

#endif