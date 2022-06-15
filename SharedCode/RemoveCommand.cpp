// Name: RemoveCommand.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions and functions for the RemoveCommand,  which removes a file with the provided name
// names of all files currently in the file system
// There is a constructor and the functions are displayInfo and execute
#include "RemoveCommand.h"
#include<iostream>
#include "Header5.h"

using namespace std; 

RemoveCommand::RemoveCommand(AbstractFileSystem* input) {
	sys = input; 
}

void RemoveCommand::displayInfo() {
	cout << "rm removes a file currently in the file system, rm can be invoked with the command : rm <filename> " << endl;
}

int RemoveCommand::execute(string fileName) {
	int result = sys->deleteFile(fileName); 
	return result; 
}

