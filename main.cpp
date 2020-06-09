/*
---------------------------------
Guess My Number (console version)
---------------------------------
*/

#include <iostream>
#include <cstdlib>

#include "headers/startprompt.hpp"
#include "headers/helpprompt.hpp"
#include "headers/play.hpp"
#include "headers/version.hpp"

using namespace std;

int main() {
    std::string user_option = start(); // initiate start menu, get response

    // decide what to do based on the user's response
    if (user_option == "play") {
        return play();
    } else if (user_option == "help") {
        return help();
    } else if (user_option == "version") {
        cout << GMN_VERSION << endl;
        return main();
    } else if (user_option == "quit") {
        return 0;
    } else {
        return main();
    }
}