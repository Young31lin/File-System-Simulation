// Name: AbstractFile.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the AbstractFile class. 
// It includes the functions and variables associated with the class. All methods are virtual and will not be defined
#pragma once


using namespace std; 
#include<vector>
#include<string>
class AbstractFileVisitor;

class AbstractFile {
public: 
	virtual vector<char> read() = 0; 
	virtual int write(vector<char> input) = 0;
	virtual int append(vector<char> input) = 0; 
	virtual unsigned int getSize() = 0; 
	virtual string getName() = 0; 
	virtual void accept(AbstractFileVisitor* ptr) = 0;
	virtual ~AbstractFile() = default; 
	virtual AbstractFile* clone(string newName) = 0; 
};
