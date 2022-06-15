// Name: RenameParsingStrategy.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function: contains functions and definitions for RenameParsingStrategy, including the functions displayInfo and parse
#include"RenameParsingStrategy.h"
#include<sstream>
#include"Header5.h"

void RenameParsingStrategy::displayInfo() {
	cout << "rn command renames an existing file, rn can be invoked with the command : rn <existing_file> <new_name_with_no_extension> " << endl;
}

vector<string> RenameParsingStrategy::parse(string input) {
	istringstream iss(input);
	string oldName; 
	string newName; 
	iss >> oldName; 
	iss >> newName; 
	string forCopy = oldName + " " + newName; 
	string forRemove = oldName; 
	vector<string> result; 
	result.push_back(forCopy); 
	result.push_back(forRemove); 
	return result; 
}