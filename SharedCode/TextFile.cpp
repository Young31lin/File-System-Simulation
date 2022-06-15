// Name: TextFile.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
//  TextFile class defined here

#include"TextFile.h"
#include"Header5.h"
#include<vector>
#include<iostream>
#include"AbstractFileVisitor.h"

using namespace std; 

TextFile::TextFile(string name_)
	: fileName(name_)
{

}
unsigned int TextFile::getSize()
{
	return (unsigned int)content.size();
}

vector<char> TextFile::read()
{
	vector<char> v;
	for (char x : content) {
		//cout << x; 
		v.push_back(x);
	}
	return v;
}

int TextFile::write(vector<char> input)
{
	content = input; 
	for (int i = 0; i < input.size(); i++) {
		if (content[i] != input[i]) {
			return fail_write; 
		}
	}
	return Success;
}

int TextFile::append(vector<char> input)
{
	int size = (int)content.size();
	for (char x : input) {
		content.push_back(x); 
	}
	int j = 0; 
	for (int i = size; i < content.size(); i++) {
		if (content[i] != input[j]) {
			return fail_append; 
		}
		j++; 
	}
	return Success;
}

string TextFile::getName()
{
	return fileName; 
}

void TextFile::accept(AbstractFileVisitor* v)
{
	v->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string newName) {
	AbstractFile* newFile = new TextFile(newName); 
	vector<char> v = this->read(); 
	int result = newFile->write(v); 
	if (result != Success) {
		return nullptr; 
	}
	return newFile;
}
