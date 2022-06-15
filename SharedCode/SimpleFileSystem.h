#pragma once
// declaration of SimpleFileSystem class goes here

#include"AbstractFileSystem.h"
#include"TextFile.h"
#include"ImageFile.h"
#include<map>
#include<set>

class SimpleFileSystem : public AbstractFileSystem {
private:
	map<string, AbstractFile*> m;
	set<AbstractFile*> fileOpened;
public: 
	virtual int addFile(string fileName, AbstractFile* p);
	//virtual int createFile(string fileName);
	virtual int deleteFile(string fileName);
	virtual AbstractFile* openFile(string fileName);
	virtual int closeFile(AbstractFile* p);
	virtual set<string> getFileNames();
	virtual ~SimpleFileSystem() = default; 
};