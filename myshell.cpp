#include <iostream>
#include "parse.hpp"

int main(int argc, char** argv) {
    //char* testString = "one two three <four >five &";

    Parse argParser(argc);
    argParser.readInput();

    std::cout << "program done!\n\n";

    return 0;
}