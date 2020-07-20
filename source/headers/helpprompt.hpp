#ifndef HELP_PROMPT_H
#define HELP_PROMPT_H

#include <iostream>

#include "misc.hpp"

int help() {
   misc::clear();

   std::cout << "Help" << std::endl
             << "----\n\n"
             << "Welcome to Guess My Number!" << std::endl
             << "This is a game where you guess a random number" << std::endl
             << "chosen by the computer. After you guess, you are" << std::endl
             << "told whether it is higher or lower than the" << std::endl
             << "computer's number (use this to your advantage!)" << std::endl
             << "If you wish to exit the program at any time," << std::endl
             << "type exit and press enter." << std::endl;

   misc::petc();


   return 0;
}

#endif