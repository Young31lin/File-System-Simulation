// Name: PasswordProxy.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the PasswordProxy class. PasswordProxy inherits AbstractFile.
// It includes the functions and variables associated with the class.
#pragma once

#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile* ptr, string p);
	virtual ~PasswordProxy();
	virtual unsigned int getSize() override;
	virtual vector<char> read() override;
	virtual int write(vector<char> input) override;
	virtual int append(vector<char> input) override;
	virtual string getName() override;
	virtual void accept(AbstractFileVisitor* ptr) override; 
	virtual AbstractFile* clone(string newName) override;
protected:
	virtual string passwordPrompt();
	virtual bool ifStringMatches(string input); 
private:
	AbstractFile* realFile;
	string password;
};