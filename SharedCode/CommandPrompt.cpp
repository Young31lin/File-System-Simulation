
// Name: CommandPrompt.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions and functions for the command prompt class. The command prompt handles user
// input/output. It is the user interface for our file system. It contains a constructor and 
// the functions setFileSystem, setFileFactory, addCommand, listCommands, prompt and run 

#include "CommandPrompt.h"
#include "Header5.h"
#include<iterator>
#include<iostream>
#include<sstream>

CommandPrompt::CommandPrompt() {
	fileSysPtr = nullptr;
	fileFactPtr = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* ptr) {
	fileSysPtr = ptr;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* ptr) {
	fileFactPtr = ptr;
}

int CommandPrompt::addCommand(string s, AbstractCommand* ptr) {
	map.insert(pair < string, AbstractCommand*>(s, ptr)); //check size if doesnt work
	if (map.find(s) != map.end()) {
		return Success;
	}
	return add_command_failure;
}

void CommandPrompt::listCommands() {
	for (auto i = map.begin(); i != map.end(); i++) {
		cout << i->first << endl; 
	}
}

string CommandPrompt::prompt() {
	string pass;
	cout << "To quit: q, For a list of Commands: help, For information about a specific command: help <command name>" << endl;
	cout << "$   "; 
	getline(cin, pass); 
	return pass;
}

int CommandPrompt::run() {
	bool keepRunning = true; 
	while (keepRunning) {
		string result = prompt(); 
		if (result.compare("q") == 0) {
			keepRunning = false; 
			return quit; 
		}
		else if (result.compare("help") == 0) {
			listCommands(); 
		}
		else if (result.find(" ") == string::npos) {
			auto it = map.find(result); 
			if (it != map.end()) {
				int res = it->second->execute("");
				if (res != Success) {
					cout << "This command failed" << endl;
				}
			}
			else {
				cout << "This command does not exist" << endl;
			}
		}
		else if (result.find(" ") != string::npos) {
			istringstream iss(result); 
			string first; 
			iss >> first; 
			if (first.compare("help") == 0) {
				string second; 
				iss >> second;
				auto it2 = map.find(second); 
				if (it2 != map.end()) {
					it2->second->displayInfo(); 
				}
				else {
					cout << "This command does not exist" << endl;
				}
			}
			else {
				auto it3 = map.find(first); 
				if (it3 != map.end()) {
					string rest; 
					string second; 
					iss >> second; 
					size_t pos = result.find(second); 
					rest = result.substr(pos); 
		
					int res2 = it3->second->execute(rest);
					if (res2 != Success) {
						cout << "This command failed" << endl;
					}
				}
				else {
					cout << "This command does not exist" << endl;
				}
			}
		}
	}
	return cpFailed;
}