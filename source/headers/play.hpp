#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include <cstdlib>

#include "misc.hpp"
#include "clear.hpp"

using namespace std;


// main game
int play() {
    system("cls");
    
    misc::query difficulty_query;
    int difficulty = difficulty_query.new_query("What difficulty do you want?",
                                                {
                                                    "Easiest (1 - 10)",
                                                    "Easy (1 - 100)",
                                                    "Medium (1 - 500)",
                                                    "Difficult (1 - 1,000)",
                                                    "Insane (1 - 1,000,000)",
                                                    "Exit"
                                                },
                                                {
                                                    "easiest",
                                                    "easy",
                                                    "medium",
                                                    "difficult",
                                                    "insane",
                                                    "exit"
                                                });
    
    int min = 1, max;
    switch (difficulty) {
        case 1: max = 10; break;
        case 2: max = 100; break;
        case 3: max = 500; break;
        case 4: max = 1000; break;
        case 5: max = 1000000; break;
        case 6: return 0;
        default: return play(); // add notice that the value was not specified, maybe a timer
    }

    /*
    --- MAIN GAME LOOP ---
    */

    while (true) {
        clear();
        cout << "Game coming soon!" << endl << "Max value specified: "
             << max << endl;
        break;
    }

    return 0;
}

#endif