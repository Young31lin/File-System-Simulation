// Name: MacroCommand.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the MacroCommand class, which inherits AbstractCommand. 
// It includes the functions and variables associated with the class.
#pragma once
#include "AbstractCommand.h"
#include"AbstractParsingStrategy.h"
#include"AbstractFileSystem.h"
#include<vector>
class MacroCommand : public AbstractCommand {
private:
	AbstractParsingStrategy* aps;
	vector<AbstractCommand*> command_v; 
	AbstractFileSystem* afs; 

public:
	MacroCommand(AbstractFileSystem* afs);
	~MacroCommand() = default;
	virtual int execute(string inputString) override;
	virtual void displayInfo() override;
	void addCommand(AbstractCommand* command);
	void setParseStrategy(AbstractParsingStrategy* input);
};
