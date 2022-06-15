// Name: MetaDataDisplayVisitor.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// definitions of metadata visitor here
#include"MetadataDisplayVisitor.h"
#include"Header5.h"
#include<iostream>
#include<iomanip>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* p)
{
	string name = p->getName(); 
	int spaceNeeded = maxFileLength - (int)(name.size());
	name.append(spaceNeeded, ' '); 
	cout << name;
	cout << "text"<< "\t" << p->getSize();
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* p)
{
	string name = p->getName();
	int spaceNeeded = maxFileLength - (int)(name.size());
	name.append(spaceNeeded, ' ');
	cout << name;
	cout << "image" << "\t" << p->getSize();
}