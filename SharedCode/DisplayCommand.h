// Name: DisplayCommand.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the DisplayCommand class. DisplayCommand is an AbstractCommand.
// It includes the functions and variables associated with the class.
#pragma once
#include "AbstractCommand.h"
#include"AbstractFileSystem.h"
#include <set>


class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys;
public:
	DisplayCommand(AbstractFileSystem* input);
	~DisplayCommand() = default;
	virtual int execute(string fileName) override;
	virtual void displayInfo() override;
};