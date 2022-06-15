// Name: CommandPrompt.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the CommandPrompt class.
// It includes the functions and variables associated with the class.
#pragma once
#include<map>
#include"AbstractCommand.h"
#include"AbstractFileSystem.h"
#include"AbstractFileFactory.h"

class CommandPrompt {
private: 
	map<string, AbstractCommand*> map; 
	AbstractFileSystem* fileSysPtr; 
	AbstractFileFactory* fileFactPtr;
public: 
	CommandPrompt(); 
	~CommandPrompt() = default; 
	void setFileSystem(AbstractFileSystem* ptr); 
	void setFileFactory(AbstractFileFactory* ptr); 
	int addCommand(string s, AbstractCommand* ptr); 
	int run(); 
protected: 
	void listCommands(); 
	string prompt(); 
};