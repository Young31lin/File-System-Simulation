
#pragma once
// TextFile declaration goes here

#include "AbstractFileSystem.h"

class TextFile: public AbstractFile {
protected: 
	vector<char> content; 
	string fileName; 
public: 
	TextFile(string name_); 
	virtual unsigned int getSize() override; 
	virtual vector<char> read() override;
	virtual int write(vector<char> input) override;
	virtual int append(vector<char> input) override;
	virtual string getName() override;
	virtual void accept(AbstractFileVisitor* v) override;
	virtual AbstractFile* clone(string newName) override; 
};