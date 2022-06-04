#ifndef QUERY_HPP
#define QUERY_HPP

#include <iostream>
#include <vector>

class Query {
    public:
        std::string input, question, answer;
        std::vector<std::string> options;
        std::vector<std::string> keys;
        int Say(bool, bool, bool);
        Query(std::string, std::vector<std::string>, std::vector<std::string>);
    private:
        /* these are to be changed to lowercase, while keeping actual input and keys
        attributes the originals */
        std::string mInput;
        std::vector<std::string> mKeys;
};

Query::Query(std::string q,
            std::vector<std::string> o = {},
            std::vector<std::string> k = {}) {
    question = q;
    options = o;
    keys = k;
}

/*
If keys is not specified, it is assumed to be equivalent to options.
Currently, this is never case sensitive.
If the user input is not in the given key, then it is returned as in its lowercase form.
*/
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
    std::cin >> input;

    // converts input to lowercase
    mInput = input;
    for (char &c : mInput) {
        c = std::tolower(c);
    }

    // if there is no options, set answer to mInput and exit
    if (options.empty()) {
        answer = mInput;
        return 0;
    }

    // if keys hasn't been defined, set it to 'options' vector
    if (keys.empty()) {
        keys = options;
        mKeys = keys;
    } else {
        mKeys = keys;
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

    // finally converts mKeys attribute to lowercase; uses shortcuts if on
    // also sets answer if key is input
    int i = 0;
    for (std::string &key : mKeys) {
        // converts key to lowercase
        for (char &c : key) {
            c = std::tolower(c);
        }
        // checks if key is equal to input, if it is then change answer and break
        if (mInput == key) {
            answer = keys.at(i);
            break;
        }
        // if allow shortcuts is on, check if input is a shortcut to this key
        if (allowShortcuts) {
            // makes sure mInput is a single character (eg, so 'pl' is not a shortcut for 'play')
            if (mInput.length() == 1) {
                if (mInput.at(0) == key.at(0)) {
                    answer = keys.at(i);
                    break;
                }
            }
        }
        
        i++;
    }
    if (answer.length() == 0) {
        answer = mInput;
    }
    return 0;
}

#endif