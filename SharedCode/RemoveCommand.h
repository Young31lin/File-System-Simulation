// Name: RemoveCommand.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the RemoveCommand class, which inherits AbstractCommand. 
// It includes the functions and variables associated with the class.
#pragma once
#include "AbstractCommand.h"
#include"AbstractFileSystem.h"
#include <set>


class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	RemoveCommand(AbstractFileSystem* input);
	~RemoveCommand() = default;
	virtual int execute(string fileName) override;
	virtual void displayInfo() override;
};

