// Name: CopyCommand.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the CopyCommand class. CopyCommand is an AbstractCommand.
// It includes the functions and variables associated with the class.
#pragma once
#include "AbstractCommand.h"
#include"AbstractFileSystem.h"


class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	CopyCommand(AbstractFileSystem* input);
	~CopyCommand() = default;
	virtual int execute(string fileName) override;
	virtual void displayInfo() override;
};