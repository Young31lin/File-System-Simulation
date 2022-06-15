// Name: ImageFile.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions and functions for ImageFile
// There is a constructor and the functions are getSize, getName, write, append, read, accept, and clone

#include"ImageFile.h"
#include"Header5.h"
#include<vector>
#include <iostream>
#include<cmath>
#include"AbstractFileVisitor.h"

using namespace std; 

ImageFile::ImageFile(string input)
	:name(input){
	size = '0';
}; 

unsigned int ImageFile::getSize() {
	return (unsigned int)contents.size(); 
}

string ImageFile::getName() {
	return name; 
}

int ImageFile::write(vector<char> input) {
	bool corrupted_file = false;
	bool sizeMismatch = false;
	bool invalidPixel = false;
	size = input[input.size() - 1]; 
	int int_size = (int)(size - '0');
	int sizeConvert = (int)pow(int_size, 2);

	if ((int)input.size() != (sizeConvert + 1)) {
		corrupted_file = true;
		sizeMismatch = true;
	}

	for (int i = 0; i < sizeConvert; i++) {
		if (input[i] == 'X' || input[i] == ' ') {
			contents.push_back(input[i]);
			
		}
		else {
			corrupted_file = true;
			invalidPixel = true;
			break; 
		}
	}

	if (corrupted_file) {
		vector<char> replace; 
		contents = replace; 
		size = 0; 

		if (sizeMismatch) {
			return size_mismatch;
		}
		else if (invalidPixel) {
			return invalid_pixel;
		}
		else {
			return corrupt_file_error;
		}
		
	}
	return Success; 
}

int ImageFile::append(vector<char> input) {
	return append_not_supported;
}

vector<char> ImageFile::read() {
	vector<char> v;
	for (unsigned int i = 0; i < contents.size(); i++) {
		v.push_back(contents[i]);
	}
	return v;
}

void ImageFile::accept(AbstractFileVisitor * v)
{
	v->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string newName) {
	AbstractFile* newFile = new ImageFile(newName);
	vector<char> v = this->read();
	int result = newFile->write(v);
	if (result != Success) {
		return nullptr;
	}
	return newFile;
}