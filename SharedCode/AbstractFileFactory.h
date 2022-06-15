// Name: AbstractFileFactory.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the AbstractFileFactory interface. 

#pragma once
#include "AbstractFile.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string fileName) = 0; 
};
