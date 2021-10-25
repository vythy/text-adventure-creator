#ifndef PARSE_HPP
#define PARSE_HPP

#include "node.hpp"

class Parse {
    private:
        // name of the file to be read from
        std::string fileName;
    public: 
        // constructor
        Parse(std::string story);

        // function that will handle reading the file and creating the game's digraph/tree
        Node* process();
};


#endif