/* miscellaneous definitions */

#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <vector>
#include <thread>
#include <chrono>
#include <limits>


namespace misc {

    class query;
    void clear_cin();
    void sleep(unsigned int);
    void petc(unsigned int);
    void clear();

    // query class w/ functions
    class query {
        public:
            int new_query(std::string, std::vector<std::string> = {}, std::vector<std::string> = {},
                          bool = true);
            std::string input;
            int input_number = 0;
    };

    int query::new_query(std::string start, std::vector<std::string> opts, std::vector<std::string> key,
                         bool say_options) {

        /*
        key is what must be typed to get a response, should
        correspond with opts as they have not been merged into a map
        */
        
        std::string user_input;

        std::cout << start << std::string(2, '\n'); // output start, add specified new lines
        
        if (say_options) {
            std::cout << "Options:" << std::endl;
        }

        for (int i = 0; i < opts.size(); i++) {
            std::cout << "    - " << opts[i] << std::endl;
        }

        std::cout << "\n: ";
        std::cin >> user_input;
        clear_cin();

        for (char &c : user_input) {
            c = std::tolower(c);
        }

        input = user_input;

        for (int i = 0; i < opts.size(); i++) {
            std::string current_option = key[i];
            
            for (char &c : current_option) {
                c = std::tolower(c);
            }
            
            if (user_input == current_option) {
                input_number = i + 1;
            }
        }

        return input_number;
    }

    // clear cin
    void clear_cin() {
        if (!std::cin) {
            std::cin.clear();
        }

        if (std::cin.peek() == '\n') {
            std::cin.get();
            return;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // sleep function
    void sleep(unsigned int ms = 2000) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    // press enter to continue function
    void petc(unsigned int sleep_time = 2000) {
        std::cout << "\nPress enter to continue...";
        clear_cin();
    }

    // clear function
    void clear() {
        #ifdef _WIN64
        system("cls"); // compatibility with both Command Line and Powershell
        #elif __linux__
        system("clear"); // compatible with Bash
        #endif
    }

}

#endif