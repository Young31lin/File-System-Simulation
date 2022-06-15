// Name: TouchCommand.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the TouchCommand class, which inherits AbstractCommand. 
// It includes the functions and variables associated with the class.
#pragma once

#include "AbstractCommand.h"
#include"AbstractFileSystem.h"
#include"AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {

private:
	AbstractFileSystem* system;
	AbstractFileFactory* factory;
public:
	TouchCommand(AbstractFileSystem* system_ptr, AbstractFileFactory* factory_ptr);
	~TouchCommand() = default;
	virtual int execute(string fileName) override;
	virtual void displayInfo() override;
};