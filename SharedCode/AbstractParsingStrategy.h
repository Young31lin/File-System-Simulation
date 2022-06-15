// Name: AbstractParsingStrategy.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the AbstractParsingStrategy interface. 
// It includes the functions and variables associated with the interface. All methods are virtual
#pragma once
#include<vector>
#include<iostream>

using namespace std; 

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string input) = 0;
	virtual void displayInfo() = 0;
};
