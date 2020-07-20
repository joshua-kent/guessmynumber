#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "misc.hpp"


// main game
int play() {
    misc::clear();
    
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

    srand((unsigned int) time(NULL)); // set random seed to time (for pseudo-random)
    int computer_number = (rand() % max) + 1;
    std::string computer_number_str = std::to_string(computer_number);
    
    int attempts = 0; // how many times the player has tried
    misc::query ask_for_user_guess;
    std::stringstream ask;
    while (true) {
        misc::clear();

        // set up heading
        ask << "Guess my number! " << "(1 - " << max << ")"
        << "\nAttempts: " << attempts;
        
        // ask user to guess
        ask_for_user_guess.new_query(ask.str(), {}, {}, false);
        std::string user_answer = ask_for_user_guess.input;

        if (user_answer == "quit") {
            return 0;
        }

        try {
            int user_answer_int = std::stoi(user_answer); // if cannot convert to int, go to catch

            if (user_answer_int == computer_number) {
                attempts++;
                std::cout << "Congratulations! You guessed after " << attempts << " attempts!" << std::endl;
                misc::sleep(); // add new header for what to do after completion
                return 0;
            } else if (user_answer_int > max) {
                std::cout << "You guessed higher than the maximum value (" << max << ")!" << std::endl;
                misc::petc();
            } else if (user_answer_int < 1) {
                std::cout << "You guessed lower than the minimum value (1)!" << std::endl;
                misc::petc();
            } else if (user_answer_int > computer_number) {
                attempts++;
                std::cout << "Your answer is greater than the computer's number." << std::endl;
                misc::petc();
            } else if (user_answer_int < computer_number) {
                attempts++;
                std::cout << "Your answer is less than the computer's number." << std::endl;
                misc::petc();
            }
        } catch (...) {
            std::cout << "Incorrect input." << std::endl;
            misc::petc();
        }

        ask.str(""); // clears 'ask' stream to empty string
        ask.clear(); // clears any flags
    }

    return 0;
}

#endif