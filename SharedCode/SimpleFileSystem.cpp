// Name: SimpleFileSystem.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu

// define methods of SimpleFileSystem class here
#include"SimpleFileSystem.h"
#include"Header5.h"
#include<iterator>


using namespace std; 

int SimpleFileSystem::addFile(string fileName, AbstractFile* p) {
	if (m.find(fileName) != m.end()||p==nullptr) {
		return file_already_exists; 
	}
	else{
		m.insert(pair<string, AbstractFile*>(fileName, p)); 
		return Success; 
	}
	return nullptr_AbstractFile;
}; 



AbstractFile* SimpleFileSystem::openFile(string fileName) {
	if (m.find(fileName) != m.end()) {
		auto it = fileOpened.find(m[fileName]); 
		if(it==fileOpened.end()){
			fileOpened.insert(m[fileName]); 
			return m[fileName]; 
		}
		else {
			return nullptr; 
		}
	}
	return nullptr; 
}

int SimpleFileSystem::closeFile(AbstractFile* p) {
	auto it = fileOpened.begin();
	while (it != fileOpened.end()) {
		if (p == *it) {
			fileOpened.erase(it); 
			return Success; 
		}
		it++; 
	}
	return file_not_open; //should change
}

int SimpleFileSystem::deleteFile(string fileName) {
	if (m.find(fileName) != m.end()) {
		auto it = fileOpened.find(m[fileName]);
		if (it == fileOpened.end()) {
			AbstractFile* tempP = m[fileName]; 
			m.erase(fileName); 
			delete tempP;
			return Success; 
		}
		else {
			return file_opened; 
		}
	}
	else {
		return file_DNE; 
	}
	
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> s; 
	for (auto it = m.begin(); it != m.end(); it++) {
		s.insert(it->first); 
	}
	return s; 
}