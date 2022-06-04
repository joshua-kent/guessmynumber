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

#endif