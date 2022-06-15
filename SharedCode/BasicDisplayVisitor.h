// Name: BasicDisplayVisitor.h
// Authors: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the declaration of the BasicDisplayVisitor class. 
// It includes the functions and variables associated with the class. 
#pragma once


#include "AbstractFileVisitor.h"
class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* p) override;
	virtual void visit_ImageFile(ImageFile* p) override;
};
