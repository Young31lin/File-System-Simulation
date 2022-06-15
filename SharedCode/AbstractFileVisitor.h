// Name: AbstractFileVisitor.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the AbstractFileVisitor interface. All methods are virtual
#pragma once
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
// studio 19 - file visitor interface declared here
class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* p) = 0; 
	virtual void visit_ImageFile(ImageFile* p) = 0; //ImageFile* ??
	virtual ~AbstractFileVisitor() = default;
	
};