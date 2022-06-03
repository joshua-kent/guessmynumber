#ifndef VERSION_H
#define VERSION_H

#include "misc.hpp"

#define PROGRAMTYPE "console" // whether run in console or window

// version info
#define GMN_VERSION "1.0.2" // Guess My Number Version
#define GMN_AUTHOR "Joshua Kent" // author
#define UPDATE_DATE "2022-06-04" // date when last updated
#define UPDATE_TIME "00:39" // time when last updated

int version() {
    misc::clear();
    std::cout << "Guess My Number " << GMN_VERSION << '\n';
    std::cout << "Last updated " << UPDATE_DATE << '\n';
    std::cout << "\nWritten by " << GMN_AUTHOR << '\n';
    std::cout << "See the official repository page at: "
                << "https://github.com/joshua-kent/guessmynumber\n";
    misc::petc();
    return 0;
}

#endif