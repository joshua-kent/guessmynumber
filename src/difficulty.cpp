#include <string>

#include "misc.hpp"
#include "query.hpp"
#include "exitprompt.hpp"
#include "difficulty.hpp"
#include "gameloop.hpp"

int difficultyPrompt() {
    int minGuess = 1, maxGuess;

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
        int confirmExit = exitprompt();
        if (confirmExit) {
            return 0;
        } else {
            return difficultyPrompt();
        }
    } else {
        return difficultyPrompt();
    }
    return play(minGuess, maxGuess);
}
