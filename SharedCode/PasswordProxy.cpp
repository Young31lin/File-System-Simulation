// Name: PasswordProxy.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function: contains functions and definitions for PasswordProxy
#include "PasswordProxy.h"
#include"Header5.h"
#include<vector>
#include <iostream>
#include<string>


using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* ptr_, string password_) 
{
	realFile = ptr_;
	password = password_;
};

PasswordProxy::~PasswordProxy() 
{
	delete realFile;
}

string PasswordProxy::passwordPrompt() 
{
	string pass;
	cout << "enter password: " << endl;
	getline(cin, pass); 
	return pass;
}

unsigned int PasswordProxy::getSize() {
	return this->realFile->getSize(); 
}

bool PasswordProxy::ifStringMatches(string input) {
	if (input.compare(password) == 0) {
		return true;
	}
	return false;
}

vector<char> PasswordProxy::read() {
	string p = passwordPrompt();
	vector<char> output;
	if (ifStringMatches(p)) {
		return (this->realFile)->read(); 
	}
	return output;
}

int PasswordProxy::write(vector<char> input) {
	string p = passwordPrompt();
	if (ifStringMatches(p)) {
		return (this->realFile)->write(input);
	}
	return incorrect_password; 
}

int PasswordProxy::append(vector<char> input) {
	string p = passwordPrompt();
	if (ifStringMatches(p)) {
		return (this->realFile)->append(input);
	}
	return incorrect_password;
}

string PasswordProxy::getName() {
	return this->realFile->getName(); 
}

void PasswordProxy::accept(AbstractFileVisitor* ptr) {
	string p = passwordPrompt();
	if (ifStringMatches(p)) {
		(this->realFile)->accept(ptr); 
	}
}

AbstractFile* PasswordProxy::clone(string newName) {
	AbstractFile* clonedRealFile = realFile->clone(newName); 
	AbstractFile* newFile = new PasswordProxy(clonedRealFile, password); 
	return newFile; 
}