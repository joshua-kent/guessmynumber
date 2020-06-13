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

    // Creates a new query instance, which can be used to
    // create new queries and retrieve the user's input
    // easily.
    class query {
        public:
            int new_query(std::string, std::vector<std::string>, std::vector<std::string> = {},
                          bool = true);
            std::string input;
            int input_number = 0;
    };

    /*
    Creates a new query for the user.

    Parameters:
    
        start (std::string) -- what is the question to be asked

        opts (std::vector<<std::string>>) -- a vector containing strings for each option

        key (std::vector<<std::string>>) -- a vector that contains corresponding strings
                                          that the user must input for the options
                                          (default: {})

                                          If the key is an empty vector '{}', automatically 
                                          set to 'opts'

        say_options (bool) -- says "Options:" before each option if set to true.
                              (default: true)
     */
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

        input = user_input; // input is an attribute of this query

        for (char &c : user_input) {
            c = std::tolower(c);
        }

        if (key.size() == 0) {
            key = opts;
        }

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

    // Clears std::cin buffer
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

    // Sleeps for some amount of milliseconds
    void sleep(unsigned int ms = 2000) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    // Displays a 'Press enter to continue' message in terminal.
    void petc() {
        std::cout << "\nPress enter to continue...";
        clear_cin();
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

#endif