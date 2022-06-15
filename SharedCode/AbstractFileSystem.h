// Name: AbstractFileSystem.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the AbstractFileSystem interface. 
// It includes the functions and variables associated with the class. All methods are virtual
#pragma once
// declaration of the interface all file systems provide goes here
#include"AbstractFile.h"
#include<set>

class AbstractFileSystem{
public:
	virtual int addFile(string fileName, AbstractFile* p) = 0;
	//virtual int createFile(string fileName) = 0; 
	virtual int deleteFile(string fileName) = 0; 
	virtual AbstractFile* openFile(string fileName) = 0;
	virtual int closeFile(AbstractFile* p) = 0; 
	virtual set<string> getFileNames() = 0; 
};