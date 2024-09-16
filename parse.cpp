#ifndef PARSE_CPP
#define PARSE_CPP
#include "parse.hpp"

Parse::Parse(int inputArgCt) {
    isRunning = true;
    parameters.setArgumentCount(inputArgCt);
}

//Takes in a token in readInput() and stores it, sets I/O directory as necessary
void Parse::discernArg(char* token) { 
    // Add argument if < or > !! I'm not sure if you're doing that
    if (token[0] == '<') {
        parameters.setOutputRedirect(token);
    }
    else if (token[0] == '>') {
        parameters.setInputRedirect(token);
    }
    parameters.addArgument(token);

}

//Loop of reading in inputs, tokenize the input string each time
void Parse::readInput() {
    
    //Get the length of the FIRST input and copy it from stdin
    // inputLength = strlen(inputLine); <- is this necessary???
    std::cout << "input here -> \n";
    getline(&inputLine, &inputLength, stdin);

    while (isRunning) {
        //Tokenize each input
        std::cout << "attempt tokenization\n";
        token = strtok(inputLine, delimiterList);
        
        while (token != NULL) {  // changed to token
            std::cout << "token is: " << token << " \n";
            discernArg(token);
            token = strtok(NULL, delimiterList);

            //Call discernArg() HERE to then decide whether it's an argument or I/O redirect
            //discernArg(token);
        }
        //By now, all tokens in inputLine should be "sorted"??

        //So now get how many arguments were added to argumentVector
        int argCt = parameters.getArgumentCount();

        //check if the inputLine is just "exit"; if it is, then... well, exit lol
        
        char** argList = parameters.getArguments();
        //For now, if 
        for (int i=0; i < argCt; i++) {
            char* tempArg = argList[i];
            std::cout << "temp arg = " << tempArg << "\n";

            int exitCheck = strcmp(tempArg, "exit");
            if (argCt == 1 && exitCheck == 0) {
                isRunning = false;
            }
        }

        if (isRunning) {
            //clear argumentVector[]
            std::cout << "$$$ ";
            getline(&inputLine, &inputLength, stdin);
        }
    }

    std::cout << "Last input into line is below.\n";
    parameters.printParams();
}

#endif