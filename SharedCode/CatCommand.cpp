// Name: CatCommand.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : definitions of the CatCommand class, used for editing and appending to files
#include "CatCommand.h"
#include<iostream>
#include<istream>
#include<fstream>
#include<sstream>
#include "Header5.h"
#include"BasicDisplayVisitor.h"
#include<string.h>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* input) {
	sys = input;
}

void CatCommand::displayInfo() {
	cout << "cat command is used for either appending text to end of file(enter -a for that) or overwriting text. Usage : cat <filename> [-a] " << endl;
}

int CatCommand::execute(string input) {
	string fileName;
	string toAppend;
	istringstream iss(input);
	iss >> fileName;
	iss >> toAppend;

	AbstractFile* af = sys->openFile(fileName); //AbstractFileSystem openFile returns an AbstractFile

	if (af == nullptr) {
		return file_cannot_open;
	}

	if (toAppend.compare("-a") == 0) { //the -a option

		AbstractFileVisitor* visitor = new BasicDisplayVisitor();
		af->accept(visitor); //AbstractFile accept with the input as BasicDisplayVistor
		cout << endl;

		cout << "input data to append to file. you can also input :wq to save and quit, or :q to quit" << endl;

		bool continue1 = true;
		string line;
		string allInput;

		while (continue1) {
			getline(cin, line);
			if (line.compare(":q") == 0) { //quit
				sys->closeFile(af); //closes the file
				continue1 = false;
				return Success;

			}
			else if (line.compare(":wq") == 0) { //save and quit
				int appendResult = 0; 
				size_t pos = fileName.find("."); 
				string checkImage = fileName.substr(pos); 
				if (checkImage.compare(".img") == 0) { //checks if it is an image file and returns failure if it is
					sys->closeFile(af);
					return fail_append; 
				}
				if (allInput.size() > strlen("\n")) { 
					vector <char> appends(allInput.size() - strlen("\n")); //accounts for the \n
					copy(allInput.begin(), allInput.end() - strlen("\n"), appends.begin());
					appendResult = af->append(appends);
				}
				sys->closeFile(af);
				continue1 = false;
				return appendResult;
			}
			else {
				allInput = allInput + line + "\n"; //adds the \n trimmed off by getline
				line.clear();
			}

		}
		return catFailed; 
	}
	else { //no -a
		// same as with the -a but now :wq overwrites data
		cout << "input data to over-write file. you can also input :wq to save and quit, or :q to quit" << endl;

		bool continue2 = true;
		string line;
		string allInput;

		while (continue2) {

			getline(cin, line);

			if (line.compare(":q") == 0) {
				sys->closeFile(af);
				continue2 = false;
				return Success;

			}
			else if (line.compare(":wq") == 0) {
				int writeResult = 0; 
				if (allInput.size() >= strlen("\n")) { //overwrite
					vector <char> reWrite(allInput.size() - strlen("\n"));
					copy(allInput.begin(), allInput.end() - strlen("\n"), reWrite.begin());
					writeResult = af->write(reWrite);
				}
				sys->closeFile(af);
				return writeResult;
			}
			else {
				allInput = allInput + line + "\n";
				line.clear();
			}

		}
		return catFailed;
	}

}