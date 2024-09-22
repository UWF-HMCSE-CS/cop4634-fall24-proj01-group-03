#ifndef PARSE_CPP
#define PARSE_CPP
#include "parse.hpp"

Parse::Parse(int inputArgCt) {
    isRunning = true;
    parameters.setArgumentCount(inputArgCt);
}

//Takes in a token in readInput() and stores it, sets I/O directory as necessary
int Parse::discernArg(char* token) { 
    if (token[0] == '<') {
        //std::cout << "size of token: " << strlen(token)-1 << "\n"; //
        if (token[1] == '\0') {
            std::cout << "A filename is required for the input redirector. Try inputting another command.\n\n";
            return 1;
        }
        parameters.setOutputRedirect(token);
    }
    else if (token[0] == '>') {
        //std::cout << "size of token: " << token[strlen(token)-1] << "\n"; //
        if (token[1] == '\0') {
            std::cout << "A filename is required for the output redirector. Try inputting another command.\n\n";
            return 1;
        }
        parameters.setInputRedirect(token);
    }
    else if (token[0] == '&') {
        parameters.setBackground(1);
    }

    parameters.addArgument(token);
    return 0;
}

//Loop of reading in inputs, tokenize the input string each time
void Parse::readInput() {
    while (isRunning) {
        parameters.clearArgVec();
        parameters.setArgumentCount(0);

        std::cout << "$$$ ";
        getline(&inputLine, &inputLength, stdin);

        //Tokenize each input
        std::cout << "attempt tokenization\n";
        token = strtok(inputLine, &delimiterList);
        
        int tempCheck = 0;
        while (token != NULL) {
            int nullCheck = strlen(token);
            if (token[nullCheck-1] == '\n') {
                token[nullCheck-1] = '\0';
            }

            std::cout << "token is: " << token << " \n";

            tempCheck = discernArg(token);
            if (tempCheck > 0) { break; }

            token = strtok(NULL, &delimiterList);
        }
        if (tempCheck > 0) { continue; }

        //So now get how many arguments were added to argumentVector
        int argCt = parameters.getArgumentCount();

        //If there were no arguments supplied, just display a ready input line again
        if (argCt == 0) { continue; }

        // BEGIN FUCKING PROBLEMS LMAO

        //std::cout << "declaring argVec and it's length\n";
        //char* argVec[MAXARGS];

        //std::cout << "attempting to getArguments()\n";
        //parameters.getArguments(argVec);
        //So argVec[] is now given the values in argumentVector[]?

        //check if the inputLine is just "exit"; if it is, then... well, exit lol
        if (argCt == 1) {
            std::string singleArg = parameters.extractArg(0);
            const char* exit = singleArg.c_str();

            std::cout << "exit check string is \"" << singleArg << "\" with a size " << singleArg.length() << "\n";

            int exitCheck = strcmp(exit, "exit");
            if (argCt == 1 && exitCheck == 0) {
                std::cout << "Read exit, terminating program\n";
                isRunning = false;
                break;
            }
        }

        std::cout << "Last input into line is below.\n";
        parameters.printParams();
        std::cout << "\n\n";
        // they should end here lmfao
    }
}

#endif