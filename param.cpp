/**
 *  param.hpp
 *  
 *  Thomas Reichherzer
 *  Copyright 2009 UWF - CS. All rights reserved.
 *
 */

#ifndef _PARAM_CPP
#define _PARAM_CPP

#include <iostream>
#include "param.hpp"
using  namespace std;

Param::Param() 
{
	inputRedirect = outputRedirect = NULL;
	background = 0;
	argumentCount = 0;
}

void Param::addArgument (char* newArgument) {
	argumentVector[argumentCount] = newArgument;

	if (newArgument[0] == '\n') {
		return;
	}
	argumentCount++;
}

int Param::getArgumentCount() {
	return argumentCount;
}

void Param::setArgumentCount(int newCount) {
	argumentCount = newCount;
}

//Take in (empty array, expected length)
//Create a temporary array on heap using malloc() ?
//Fill each index of **tempArray with the argument supplied to *argumentVector[] ??
//Implementing his function seemed like a lot more effort than it was worth
void Param::getArguments(char** argDest) {

	for (int i=0; i < argumentCount; i++) {
		//for (int j=0; j < )
		//std::cout << "Inserting " << argumentVector[i][i] << " into argVec in parse.cpp\n"; //
	}

	/*
	char** tempArray, size_t* len;
	
	char *temp = (char*) malloc(argumentCount+1);

	for (int i=0; i < argumentCount; i++) {
		tempArray[i] = temp;
		std::cout << argumentVector[i] << "\n"; //
	}

	*len = argumentCount;
	*/


	//*tempArray = argumentVector;
}

std::string Param::extractArg(int indexAt) {
	std::string temp;
	std::stringstream arg;
	arg.str(std::string());

	arg << argumentVector[indexAt];
	temp = arg.str();
	return temp;
}

void Param::setInputRedirect(char *newInputRedirect) {
	inputRedirect = newInputRedirect;
}

void Param::setOutputRedirect(char *newOutputRedirect) {
	outputRedirect = newOutputRedirect;
}
		
void Param::setBackground(int newBackground) {
	background = newBackground;
}

char* Param::getInputRedirect() {
	return inputRedirect;
}
		
		
char* Param::getOutputRedirect() {
	return outputRedirect;
}
		
int Param::getBackground() {
    return background;
}

void Param::clearArgVec() {
    for (int i = 0; i < MAXARGS; i++) {
        argumentVector[i] = NULL;
    }
}


void Param::printParams() {
	cout << "InputRedirect: [" 
	     << (inputRedirect != NULL) ? inputRedirect : "NULL";
	cout << "]" 
	     << endl 
		 <<	"OutputRedirect: [" 
		 << (outputRedirect != NULL) ? outputRedirect : "NULL";
	cout << "]" 
	     << endl 
		 << "Background: [" 
		 << background 
		 << "]" 
		 << endl 
		 << "ArgumentCount: [" 
		 << argumentCount 
		 << "]" 
		 << endl;
	for (int i = 0; i < argumentCount; i++)
		cout << "ArgumentVector[" 
			 << i 
			 << "]: [" 
			 << argumentVector[i] 
			 << "]" 
			 << endl;
}

#endif
