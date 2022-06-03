#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "misc.hpp"


// main game
int play() {
    misc::clear();
    
    misc::Query DifficultyQuery("What difficulty do you want?",
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
    DifficultyQuery.Say();
    std::string difficulty = DifficultyQuery.answer;
    int min = 1;
    int max;
    if (difficulty == "easiest") {
        max = 10;
    } else if (difficulty == "easy") {
        max = 100;
    } else if (difficulty == "medium") {
        max = 500;
    } else if (difficulty == "difficult") {
        max = 1000;
    } else if (difficulty == "insane") {
        max = 1000000;
    } else if (difficulty == "exit") {
        return 0;
    } else {
        return play(); //TODO: add notice that the value was not specified, maybe a timer
    }

    /*
    --- MAIN GAME LOOP ---
     */

    srand((unsigned int) time(NULL)); // set random seed to time (for pseudo-random)
    int correctNumber = (rand() % max) + 1;
    
    int attempts = 0; // how many times the player has tried
    std::stringstream ask;
    while (true) {
        misc::clear();

        // set up heading
        ask << "Guess my number! " << "(1 - " << max << ")"
        << "\nAttempts: " << attempts;
        
        // ask user to guess
        misc::Query UserGuess(ask.str());
        UserGuess.Say(false);

        if (UserGuess.answer == "quit") {
            return 0;
        }

        //try {
            // if cannot convert to int, go to catch
        //int guess = std::stoi(UserGuess.answer);
        int guess = 5;

            if (guess == correctNumber) {
                attempts++;
                std::cout << "Congratulations! You guessed after " << attempts << " attempts!" << std::endl;
                misc::sleep(); // add new header for what to do after completion
                return 0;
            } else if (guess > max) {
                std::cout << "You guessed higher than the maximum value (" << max << ")!" << std::endl;
            } else if (guess < 1) {
                std::cout << "You guessed lower than the minimum value (1)!" << std::endl;
            } else if (guess > correctNumber) {
                attempts++;
                std::cout << "Your answer is greater than the computer's number." << std::endl;
            } else if (guess < correctNumber) {
                attempts++;
                std::cout << "Your answer is less than the computer's number." << std::endl;
            }
            /*
        } catch (...) {
            std::cout << "Incorrect input." << std::endl;
        }*/
        misc::petc();

        ask.str(""); // clears 'ask' stream to empty string
        ask.clear(); // clears any flags
    }

    return 0;
}

#endif

int a = play();