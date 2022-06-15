#pragma once
#include "AbstractFileFactory.h"
#include "ImageFIle.h"
#include "TextFile.h"
// Studio 18 - simplefilefactory class declaration goes here
class SimpleFileFactory : public AbstractFileFactory {
public: 
	AbstractFile* createFile(string fileName);
}; 

