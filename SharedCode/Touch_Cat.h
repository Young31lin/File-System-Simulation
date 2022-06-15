// Name: Touch_Cat.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the Touch_Cat class, which inherits AbstractParsingStrategy. 
// It includes the functions and variables associated with the class.  
#pragma once
#include "AbstractParsingStrategy.h"
#include<iostream>

using namespace std;

class Touch_Cat : public AbstractParsingStrategy {
	virtual vector<string> parse(string input) override;
	virtual void displayInfo() override;
};
