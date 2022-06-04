#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include <sstream>
#include <ctime>

#include "misc.hpp"
#include "query.hpp"


// main game
int play() {
    int max, guess;
    int min = 1;
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

    // get max value from difficulty and set computer's random number accordingly
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
    } else if (difficulty == "quit" || difficulty == "exit") {
        return 0;
    } else {
        return play(); //TODO: add notice that the value was not specified, maybe a timer
    }
    correctNumber = (rand() % max) + 1;

    /*
    --- MAIN GAME LOOP ---
     */
    
    while (true) {
        isValid = true; // clears isValid (if it was set false in last iteration)
        misc::clear();

        // ask user to guess
        ask << "Guess my number! " << "(1 - " << max << ")"
        << "\nAttempts: " << attempts;
        Query UserGuess(ask.str());
        UserGuess.Say(false);

        if (UserGuess.answer == "quit" || UserGuess.answer == "exit") {
            return 0;
        }

        try {
            guess = std::stoi(UserGuess.answer);
        } catch (std::invalid_argument) {
            std::cout << "Incorrect input." << '\n';
            isValid = false;
        }

        if (isValid) {
            if (guess == correctNumber) {
                attempts++;
                std::cout << "Congratulations! You guessed after " << attempts << " attempts!" << '\n';
                misc::sleep(); //TODO: add new header for what to do after completion
                return 0;
            } else if (guess > max) {
                std::cout << "You guessed higher than the maximum value (" << max << ")!" << '\n';
            } else if (guess < 1) {
                std::cout << "You guessed lower than the minimum value (1)!" << '\n';
            } else if (guess > correctNumber) {
                attempts++;
                std::cout << "Your answer is greater than the computer's number." << '\n';
            } else if (guess < correctNumber) {
                attempts++;
                std::cout << "Your answer is less than the computer's number." << '\n';
            }
        }
        misc::petc();

        ask.str(""); // clears 'ask' stream to empty string
        ask.clear(); // clears any flags
    }

    return 0;
}

#endif