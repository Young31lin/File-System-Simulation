
// Name: Lab5.cpp
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function: This file contains the 'main' function. The program executes here and runs the commands.

#include"..\..\\SharedCode\RenameParsingStrategy.h"
#include"..\..\\SharedCode\CopyCommand.h"
#include"..\..\\SharedCode\SimpleFileSystem.h"
#include"..\..\\SharedCode\RemoveCommand.h"
#include"..\..\\SharedCode\MacroCommand.h"
#include"..\..\\SharedCode\CommandPrompt.h"
#include"..\..\\SharedCode\AbstractFileFactory.h"
#include"..\..\\SharedCode\SimpleFileFactory.h"
#include"..\..\\SharedCode\TouchCommand.h"
#include"..\..\\SharedCode\CatCommand.h"
#include"..\..\\SharedCode\LSCommand.h"
#include"..\..\\SharedCode\DisplayCommand.h"

int main()
{
	CommandPrompt cp; 
	AbstractFileSystem* afs = new SimpleFileSystem(); 
	AbstractFileFactory* aff = new SimpleFileFactory(); 
	cp.setFileSystem(afs); 
	cp.setFileFactory(aff); 


	//Adding Commands
	AbstractCommand* ls = new LSCommand(afs); 
	cp.addCommand("ls", ls); 

	AbstractCommand* cat = new CatCommand(afs);
	cp.addCommand("cat", cat);

	AbstractCommand* copy_command = new CopyCommand(afs);
	cp.addCommand("cp", copy_command);

	AbstractCommand* ds = new DisplayCommand(afs);
	cp.addCommand("ds", ds);

	AbstractCommand* rm = new RemoveCommand(afs);
	cp.addCommand("rm", rm);

	AbstractCommand* touch = new TouchCommand(afs, aff);
	cp.addCommand("touch", touch);
	

	//Rename MacroCommand
	RenameParsingStrategy* rps = new RenameParsingStrategy; 
	AbstractCommand* copy = new CopyCommand(afs); 
	AbstractCommand* remove = new RemoveCommand(afs);
	MacroCommand* mac = new MacroCommand(afs); 
	mac->setParseStrategy(rps); 
	mac->addCommand(copy); 
	mac->addCommand(remove); 
	cp.addCommand("rn", mac); 

	//Touch-Cat MacroCommand
	MacroCommand* mac2 = new MacroCommand(afs);
	RenameParsingStrategy* rps2 = new RenameParsingStrategy;
	AbstractCommand* touch1 = new TouchCommand(afs,aff);
	AbstractCommand* cat1 = new CatCommand(afs);
	mac2->setParseStrategy(rps2); 
	mac2->addCommand(touch1); 
	mac2->addCommand(cat1); 
	cp.addCommand("ce", mac2); 
	
	return cp.run();
}


