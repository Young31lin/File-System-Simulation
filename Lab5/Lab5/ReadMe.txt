Author: Young Lin and Ajay Gupta
CSE 332 - Lab 4

Program Description: 
This program provides different commands to files. Since all of the files are stored in a file system, they can be accessed on demand once it is created.

How work was split: 
We each worked on separate parts of Lab5 on our own, but then finished and went over each part together.
Young did most of the testing and Ajay did all comments, enums and the ReadMe.

Design Choices: 
1. When one decides to override a file by making it blank, entering only :wq will not over-write it. Instead, an empty line is needed for :eq to empty
the files' content.
2. When calling cat append on a text file, if a '\n' is not provided before the input, a line is not skipped when adding to the contents of the file. 

Part 9 Additional MacroCommand:
We decided to do a MacroCommand that adds the touch + cat functionality so that the user can create a file and edit it immediately. 
We called it Touch_Cat and the class inherits AbstractParsingStrategy. In the parse method we push_back the fileName into the vector<string>, and then push_back
the whole input for the CatCommand portion.
We tested Touch_Cat by inputting different fileNames and edits in the form "ce <fileName>" to create file and "<edit to file>" after cat is called.

Errors/Bugs:
1. One of the errors we encountered was when one some of the variables from another class were "inaccessable". This was
because of the fact that we did not make the variables from the other class public.
2. After entering a password, "this command does not exists" appears in the prompt, which causes a re-prompt to occur. This problem 
arose because I used cin instead of getline in the passowrdPrompt of PasswordProxy.cpp. 
3. An error arose when I did not return failure when the user attempts to append an image file. 
4. I originially used setw for lsCommand formatting, which created an error as it only sets width in the beginning. 

Tests:
1. Tested by calling touch, cat, and display on image/text files.
2. Called cat -a on a image file, which lead to failure. 
3. Displayed image files in both the unformatted and formatted style. 
4. Called ls and ls -m to ensure that all files are displayed, along with its metaData. 
5. Tested the rename method by renaming it and calling ds on it. It worked! When ds was called on the original name, it failed. 
6. Tested copy method by calling it on a text file. I appened the new text file, and printed both files. They generated two different prints.
7. I removed a file, and called ls to make sure taht the file no longer exists in the system. 
8. Tested the Touch_Cat macrocommand by creating a text file and overwriting it with cat. 



