// Name: CopyCommand.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions and functions for the copy command, which copies a file
// that exists in the file system and adds the copy to the file system with a different name
// there is a constructor and the functions are displayInfo and execute
#include"CopyCommand.h"
#include<iostream>
#include<sstream>
#include"Header5.h"

using namespace std; 

CopyCommand::CopyCommand(AbstractFileSystem* input) {
	sys = input;
}

void CopyCommand::displayInfo(){
	cout << "cp copies a file that exists in the file system and adds it to the file system with a different name." << endl;
	cout << "cp can be invoked with the command : cp <name of file to copy> <new name with no extension>" << endl;
}

int CopyCommand::execute(string fileName) {
	string oldFileName; 
	string newFileName; 
	istringstream iss(fileName); 
	iss >> oldFileName; 
	iss >> newFileName; 

	size_t pos = oldFileName.find("."); //pos of the "."
	string fileType = oldFileName.substr(pos); //get the file type 
	string fullName = newFileName + fileType; //make new file name
	AbstractFile* af = sys->openFile(oldFileName); 
	if (af == nullptr) {
		return file_cannot_open; 
	}
	AbstractFile* copyFile = af->clone(fullName); //make the clone
	if (copyFile == nullptr) {
		return file_cannot_clone; 
	}
	sys->closeFile(af); //close file
	int result = sys->addFile(fullName, copyFile); 
	return result; 

}