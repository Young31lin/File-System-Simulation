// Name: LSCommand.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the LSCommand class, which inherits AbstractCommand. 
// It includes the functions and variables associated with the class.
#pragma once
#include "AbstractCommand.h"
#include"AbstractFileSystem.h"
#include <set>


class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public: 
	LSCommand(AbstractFileSystem* input);
	~LSCommand() = default;
	virtual int execute(string fileName) override;
	virtual void displayInfo() override;
};