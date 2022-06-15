// Name: BasicDisplayVisitor.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions of basic display visitor here

#include"BasicDisplayVisitor.h"
#include<vector>
#include<iostream>
#include<math.h>

using namespace std; 

void BasicDisplayVisitor::visit_TextFile(TextFile* p) 
{
	vector<char> v = p->read();
	for (char x : v) {
		cout << x;
	}
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* p)
{
	vector<char> v = p->read();
	int size = (int)sqrt(v.size());
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << v[(size_t)((i * size) + j)];
		}
		cout << endl; 
	}
}

