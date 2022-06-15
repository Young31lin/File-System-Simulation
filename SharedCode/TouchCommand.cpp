// Name: TouchCommand.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function: contains functions and definitions for TouchCommand, including a constructor and the functions displayInfo and execute
// The command touch can create a file that is password protected
#include "TouchCommand.h"
#include"PasswordProxy.h"
#include "Header5.h"
#include <iostream>
#include<sstream>

TouchCommand::TouchCommand(AbstractFileSystem* system_ptr, AbstractFileFactory* factory_ptr) {
	system = system_ptr;
	factory = factory_ptr;
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch <filename> or touch <filename> -p" << endl;
	cout << "<-p> creates a password protected file" << endl; 
}

int TouchCommand::execute(string input) {
	istringstream iss(input); 
	string fileName; 
	string pCommand; 
	iss >> fileName; 
	iss >> pCommand; 

	AbstractFile* file = this->factory->createFile(fileName);
	if (file == nullptr) {
		return create_file_error;
	}
	else {
		int output; 
		if (pCommand.compare("-p") == 0) {
			string password; 
			cout << "Enter the password" << endl; 
			getline(cin, password); 
			PasswordProxy* p = new PasswordProxy(file, password); 
			output = system->addFile(fileName, p);
			if (output != Success) {
				delete file;
				delete p;
				return not_added_to_file_system; //file was created successfully but was not added to the filesystem correctly
			}
		}
		else {
			output = system->addFile(fileName, file);
			if (output != Success) {
				delete file;
				return not_added_to_file_system; //file was created successfully but was not added to the filesystem correctly
			}
		}
		return Success; 
	}
}