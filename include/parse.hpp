#ifndef PARSE_HPP
#define PARSE_HPP

#include "node.hpp"

class Parse {
    private:
        std::string fileName;
    public: 
        Parse(std::string story);
        Node* process();
};


#endif