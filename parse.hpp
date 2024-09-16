#ifndef PARSE_HPP
#define PARSE_HPP
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "param.hpp"

class Parse {
    private:
        Param parameters;
        size_t inputLength = 64; //why would it need to be larger than this tbh
        char* inputLine;
        char* token;
        char* delimiterList = " ";
        bool isRunning;
    public:
        Parse(int inputArgCt);
        void readInput();
        void discernArg(char* token);
};

#endif