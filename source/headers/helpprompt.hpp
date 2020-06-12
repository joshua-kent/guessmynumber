#ifndef HELP_PROMPT_H
#define HELP_PROMPT_H

#include <iostream>

#include "misc.hpp"

int help() {
   misc::clear();

   std::cout << "Help" << std::endl
             << "----\n\n"
             << "Welcome to Guess My Number!" << std::endl
             << "This";


   return 0;
}

#endif