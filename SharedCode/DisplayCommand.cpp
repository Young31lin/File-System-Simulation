// Name: DisplayCommand.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions and functions for the display command, which opens a file
// and displays its contents
// there is a constructor and the functions are displayInfo and execute

#include"DisplayCommand.h"
#include<iostream>
#include"Header5.h"
#include<sstream>
#include"BasicDisplayVisitor.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* input) {
	sys = input; 
}

void DisplayCommand::displayInfo() {
	cout << "ds displays a file in the filesystem, ds can be invoked with the command : ds <filename> or ds <filename> -d " << endl;
	cout << "ds <filename> prints out the formatted version, while ds <filename> -d prints out the unformatted version" << endl;
}

int DisplayCommand::execute(string fileName){
	string name; 
	string displayType; 
	istringstream iss(fileName); 
	iss >> name;
	iss >> displayType;
	AbstractFile* af = sys->openFile(name); 
	if (af == nullptr) {
		return file_cannot_open;
	}
	if (displayType.compare("-d") != 0) {
		AbstractFileVisitor* visitor = new BasicDisplayVisitor(); 
		af->accept(visitor); 
		cout << endl; 
		sys->closeFile(af);
	}
	else {
		vector<char> v; 
		v = af->read(); 
		for (unsigned int i = 0; i < v.size(); i++) {
			cout << v[i]; 
		}
		cout << endl; 
		sys->closeFile(af);
	}
	return Success; 
}