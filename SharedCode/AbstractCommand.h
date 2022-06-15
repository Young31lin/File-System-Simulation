// Name: AbstractCommand.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the AbstractCommand class. 
// It includes the functions and variables associated with the class.
#pragma once
#include <string>

using namespace std; 

class AbstractCommand {
public:
	virtual int execute(string input) = 0; 
	virtual void displayInfo() = 0; 
	~AbstractCommand() = default; 

};