// Name: ImageFile.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the ImageFile class.
// It includes the functions and variables associated with the class.
#pragma once
// Image file class declaration here
#include"AbstractFileSystem.h"
#include <string>
#include<vector>

class ImageFile : public AbstractFile {
protected: 
	string name; 
	vector<char> contents; 
	char size; 
public: 
	ImageFile(string input); 
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char> input); 
	virtual int append(vector<char> input); 
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor* v);
	virtual AbstractFile* clone(string newName) override;
};