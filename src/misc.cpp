#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <vector>
#include <thread>
#include <chrono>
#include <limits>


namespace misc {
    // Clears std::cin buffer
    void clearCin() {
        if (!std::cin) {
            std::cin.clear();
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Sleeps for some amount of milliseconds
    void sleep(unsigned int ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    // Displays a 'Press enter to continue' message in terminal.
    void petc() {
        clearCin();
        std::cout << "\nPress enter to continue...";
        std::cin.get();
    }

    // Clears the terminal screen
    void clear() {
        #ifdef _WIN64
        system("cls"); // compatibility with both Command Line and Powershell
        #elif __linux__
        system("clear"); // compatible with Bash
        #endif
    }

}