// Name: MacroCommand.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions and functions for the MacroCommands, which allow us to construct commands out of other commands
// There is a constructor and the functions are displayInfo, execute, addCommand and setParseStrategy

#include "MacroCommand.h"
#include<iostream>
#include "Header5.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* input) {
	afs = input;  
	aps = nullptr; 
}

void MacroCommand::displayInfo() {
	cout << "Macrocommands execute each of the commands it is composed of in order. Below is the list of Macrocommands." << endl; 
	cout <<  "rn command renames an existing file, rn can be invoked with the command : rn <existing_file> <new_name_with_no_extension> " << endl; 
	cout << "ce command creates a file and then immediately edits it with the command : ce <fileName>" << endl; 
}

int MacroCommand::execute(string inputString) {
	vector<string> string_v = aps->parse(inputString);
	for (int i = 0; i < string_v.size(); i++) {
		int output = command_v[i]->execute(string_v[i]);
		if (output != Success) {
			return output;
		}
	}

	return Success;
}

void MacroCommand::addCommand(AbstractCommand* command) {
	command_v.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* input) {
	aps = input;
}