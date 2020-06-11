#ifndef CLEAR_H
#define CLEAR_H

#include <cstdlib>


void clear() {
    #ifdef _WIN64
    system("cls"); // compatibility with both Command Line and Powershell
    #elif __linux__
    system("clear"); // compatible with Bash
    #endif
}


#endif