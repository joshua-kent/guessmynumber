#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include <ctime>
#include <sstream>

#include "misc.hpp"
#include "query.hpp"
#include "exitprompt.hpp"


// main game
int play() {
    int maxGuess, guess;
    int minGuess = 1;
    int attempts = 0;
    std::stringstream ask;
    // set random seed to time (for pseudo-random)
    srand((unsigned int) time(NULL));
    int correctNumber;
    bool isValid = true;

    misc::clear();
    
    Query DifficultyQuery("What difficulty do you want?",
                        {
                            "Easiest (1 - 10)",
                            "Easy (1 - 100)",
                            "Medium (1 - 500)",
                            "Difficult (1 - 1,000)",
                            "Insane (1 - 1,000,000)",
                            "Quit"
                        },
                        {
                            "easiest",
                            "easy",
                            "medium",
                            "difficult",
                            "insane",
                            "quit"
                        });
    DifficultyQuery.Say();
    std::string difficulty = DifficultyQuery.answer;

    // get maxGuess value from difficulty and set computer's random number accordingly
    if (difficulty == "easiest") {
        maxGuess = 10;
    } else if (difficulty == "easy") {
        maxGuess = 100;
    } else if (difficulty == "medium") {
        maxGuess = 500;
    } else if (difficulty == "difficult") {
        maxGuess = 1000;
    } else if (difficulty == "insane") {
        maxGuess = 1000000;
    } else if (difficulty == "quit" || difficulty == "exit" || difficulty == "q") {
        int confirmExit = exit();
        if (confirmExit) {
            return 0;
        } else {
            return play();
        }
    } else {
        return play();
    }
    correctNumber = (rand() % maxGuess) + 1;



    /* --- MAIN GAME LOOP --- */
    
    while (true) {
        isValid = true; // clears isValid (if it was set false in last iteration)
        misc::clear();

        ask << "Guess my number! (" << minGuess << " - " << maxGuess << ")\n"
            << "Attempts: " << attempts;
        Query UserGuess(ask.str());
        std::stringstream().swap(ask); // clears buffer contents and flags, for next iteration

        UserGuess.Say(false); // get user response

        if (UserGuess.answer == "quit" || UserGuess.answer == "exit" || UserGuess.answer == "q") {
            int confirmExit = exit();
            if (confirmExit) {
                return 0;
            } else {
                continue;
            }
        }

        // validates that guess is an integer
        try {
            guess = std::stoi(UserGuess.answer);
        } catch (std::invalid_argument) {
            std::cout << "Incorrect input.\n";
            isValid = false;
        }

        if (isValid) {
            if (guess == correctNumber) {
                attempts++;
                std::cout << "Congratulations! You guessed after " << attempts << " attempts!\n";
                misc::sleep(); //TODO: add new header for what to do after completion
                return 0;
            } else if (guess > maxGuess) {
                std::cout << "You guessed higher than the maximum value (" << maxGuess << ")!\n";
            } else if (guess < minGuess) {
                std::cout << "You guessed lower than the minimum value (" << minGuess << ")!\n";
            } else if (guess > correctNumber) {
                attempts++;
                std::cout << "Your answer is greater than the computer's number.\n";
            } else if (guess < correctNumber) {
                attempts++;
                std::cout << "Your answer is less than the computer's number.\n";
            }
        }
        misc::petc();
    }

    return 0;
}

#endif