// Name: Touch_Cat.cpp
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function: contains the functions for Touch Cat, which is a command that creates a file and allows for immediate editing
// the functions are displayInfo and parse
#include"Touch_Cat.h"
#include<sstream>
#include"Header5.h"

void Touch_Cat::displayInfo() {
	cout <<  "ce command creates a file and then immediately edits it with the command : ce <fileName>" << endl;
}

vector<string> Touch_Cat::parse(string input) {
	istringstream iss(input);
	string fileName;
	iss >> fileName;
	vector<string> v;
	v.push_back(fileName);
	v.push_back(input); //this is the input for CatCommand; it takes the whole input
	return v;


}