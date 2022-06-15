// Name: RenameParsingStrategy.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the RenameParsingStrategy class. RenameParsingStrategy inherits AbstractParsingStrategy.
// It includes the functions and variables associated with the class.
#pragma once
#include "AbstractParsingStrategy.h"
#include<iostream>

using namespace std; 

class RenameParsingStrategy : public AbstractParsingStrategy {
public: 
	virtual vector<string> parse(string input) override; 
	virtual void displayInfo() override; 
};