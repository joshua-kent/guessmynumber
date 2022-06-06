#include <iostream>

#include "misc.hpp"
#include "version.hpp"

int version() {
    misc::clear();
    std::cout << "Guess My Number " << VERSION << '\n';
    std::cout << "Last updated " << UPDATE_DATE << '\n';
    std::cout << "\nWritten by " << AUTHOR << '\n';
    std::cout << "See the official repository page at: "
                << "https://github.com/joshua-kent/guessmynumber\n";
    misc::petc();
    return 0;
}