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
    void clearCin();
    void sleep(unsigned int);
    void petc(unsigned int);
    void clear();

    // Creates a new query instance, which can be used to
    // create new queries and retrieve the user's input
    // easily.
    //TODO: move query to its own header
    class Query {
        public:
            std::string input, question, answer;
            std::vector<std::string> options;
            std::vector<std::string> keys;
            int Say(bool, bool, bool);
            Query(std::string, std::vector<std::string>, std::vector<std::string>);
        private:
            std::string mInput;
            std::vector<std::string> mOptions;
            std::vector<std::string> mKeys;
    };

    Query::Query(std::string q,
                std::vector<std::string> o = {},
                std::vector<std::string> k = {}) {
        question = q;
        options = o;
        keys = k;
    }

    int Query::Say(bool sayOptions = true, bool allowShortcuts = false, bool allowIndices = true) {
        // say question
        std::cout << question << "\n\n";
        
        // states options if wanted
        if (sayOptions) {
            std::cout << "Options:" << '\n';
            for (const std::string &option : options) {
                std::cout << "    - " << option << '\n';
            }
        }

        // gets input
        std::cout << "Input: ";
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //std::getline(std::cin, input);
        std::cin >> input;

        // if there is no options, set answer to input and exit
        if (options.empty()) {
            answer = input;
            return 0;
        }

        // checks if input is an index; if it is, then answer is set to relevant index
        if (allowIndices) {
            try {
                int _input = std::stoi(input);
                if (_input > 0 && _input <= keys.size()) {
                    answer = keys.at(_input - 1);
                    return 0;
                }
            } catch (std::invalid_argument) {}
        }

        // converts input and options attributes to lowercase; uses shortcuts if on
        mInput = input;
        if (allowShortcuts) {
            mInput = mInput.at(0);
        }
        for (char &c : mInput) {
            c = std::tolower(c);
        }
        mOptions = options;
        for (std::string &option : mOptions) {
            if (allowShortcuts) {
                option = option.at(0);
            }
            for (char &c : option) {
                c = std::tolower(c);
            }
        }

        // if keys hasn't been defined, set it to 'options' vector
        if (keys.empty()) {
            mKeys = options;
        } else {
            mKeys = keys;
        }

        // finally converts keys attribute to lowercase; uses shortcuts if on
        // also sets answer if key is input
        int i = 0;
        for (std::string &key : mKeys) {
            if (allowShortcuts) {
                key = key.at(0);
            }
            for (char &c : key) {
                c = std::tolower(c);
            }

            if (mInput == key) {
                answer = keys.at(i);
            }
            i++;
        }
        return 0;
    }

    // Clears std::cin buffer
    void clearCin() {
        if (!std::cin) {
            std::cin.clear();
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Sleeps for some amount of milliseconds
    void sleep(unsigned int ms = 2000) {
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

#endif