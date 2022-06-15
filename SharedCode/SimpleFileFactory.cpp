// Name: SimpleFileFactory.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"

using namespace std; 

AbstractFile* SimpleFileFactory::createFile(string fileName) {
	if (fileName.find("txt")!= std::string::npos) {
		AbstractFile* tp = new TextFile(fileName);
		return tp; 
	}
	else if (fileName.find("img")!= std::string::npos) {
		AbstractFile* ip = new ImageFile(fileName);
		return ip; 
	}
	else {
		return nullptr;
	}
}