#ifndef EXIT_PROMPT_H
#define EXIT_PROMPT_H


#include <iostream>
#include <string>
// TODO: create an actual exit prompt (confirm exit)

int exit() {
    std::string answer;

    std::cout << "Are you really sure you want to exit? (Y/N): ";
    std::cin >> answer;
    
    // convert answer to lowercase
    for (char &c : answer) {
        c = c.to_lower();
    }

    return 0;
}

#endif