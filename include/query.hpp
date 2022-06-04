#ifndef QUERY_HPP
#define QUERY_HPP

#include <vector>
#include <string>

class Query {
    public:
        std::string input, question, answer;
        std::vector<std::string> options;
        std::vector<std::string> keys;
        int Say(bool = true, bool = false, bool = true);
        Query(std::string, std::vector<std::string> = {}, std::vector<std::string> = {});
    private:
        /* these are to be changed to lowercase, while keeping actual input and keys
        attributes the originals */
        std::string mInput;
        std::vector<std::string> mKeys;
};

#endif