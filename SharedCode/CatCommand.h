// Name: CatCommand.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the CatCommand class. CatCommand is an AbstractCommand.
// It includes the functions and variables associated with the class.

#pragma once
#include "AbstractCommand.h"
#include"AbstractFile.h"
#include"AbstractFileSystem.h"


class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	CatCommand(AbstractFileSystem* input);
	~CatCommand() = default;
	virtual int execute(string fileName) override;
	virtual void displayInfo() override;
};
