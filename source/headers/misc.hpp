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

using namespace std;


namespace misc {

    class query;
    void clear_cin();
    void sleep(unsigned int);
    void petc(unsigned int);
    void clear();

    // query class w/ functions
    class query {
        public:
            int new_query(string, vector<string> = {}, vector<string> = {},
                          bool = true);
            string input;
            int input_number = 0;
    };

    int query::new_query(string start, vector<string> opts, vector<string> key,
                         bool say_options) {

        /*
        key is what must be typed to get a response, should
        correspond with opts as they have not been merged into a map
        */
        
        string user_input;

        cout << start << string(2, '\n'); // output start, add specified new lines
        
        if (say_options) {
            cout << "Options:\n";
        }

        for (int i = 0; i < opts.size(); i++) {
            cout << "    - " << opts[i] << endl;
        }

        cout << "\n: ";
        cin >> user_input;
        clear_cin();

        for (char &c : user_input) {
            c = tolower(c);
        }

        input = user_input;

        for (int i = 0; i < opts.size(); i++) {
            string current_option = key[i];
            
            for (char &c : current_option) {
                c = tolower(c);
            }
            
            if (user_input == current_option) {
                input_number = i + 1;
            }
        }

        return input_number;
    }

    // clear cin
    void clear_cin() {
        if (!cin) {
            cin.clear();
        }

        if (cin.peek() == '\n') {
            cin.get();
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // sleep function
    void sleep(unsigned int ms = 2000) {
        this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    // press enter to continue function
    void petc(unsigned int sleep_time = 2000) {
        cout << "\nPress enter to continue...";
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