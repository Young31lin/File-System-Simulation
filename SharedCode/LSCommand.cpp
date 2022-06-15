// Name: LSCommand.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions and functions for the LSCommand,  which outputs to the terminal the
// names of all files currently in the file system
// There is a constructor and the functions are displayInfo and execute

#include"LSCommand.h"
#include<iostream>
#include<iomanip>
#include"AbstractFileVisitor.h"
#include"MetadataDisplayVisitor.h"
#include"AbstractFileSystem.h"
#include"Header5.h"

LSCommand::LSCommand(AbstractFileSystem* input) {
	sys = input;
};

void LSCommand::displayInfo() {
	cout <<"ls lists out all the files currently in the file system, ls can be invoked with the command : ls or ls -m " << endl;
	cout << "ls prints out only the file names and ls -m prints out the file name and metadata associated with that file" << endl; 
}

int LSCommand::execute(string fileName) {
	set<string> cSet = sys->getFileNames(); 

	if (fileName.compare("") == 0) {
		int counting = 0; 
		for (auto it2 = cSet.begin(); it2 != cSet.end(); it2++) {
			string name = *it2; 
			if (counting % 2 == 0) {
				int spaceNeeded = maxFileLength - (int)(name.size());
				name.append(spaceNeeded, ' ');
				if (counting != 0) {
					cout << endl;
				}
			}

			cout << name; 
			counting++; 

		}
		cout << endl; 
	}
	else if (fileName.compare("-m") == 0) {
		for (auto it = cSet.begin(); it != cSet.end(); it++) {
			AbstractFileVisitor *visitor = new MetadataDisplayVisitor(); 
			AbstractFile* file = sys->openFile(*it); 
			if (file == nullptr) {
				return file_cannot_open;
			}
			file->accept(visitor); 
			sys->closeFile(file); 
			cout << endl;
		}
		cout << endl; 
	}
	else {
		return commandPrompt_input_failure;
	}
	return Success; 
}