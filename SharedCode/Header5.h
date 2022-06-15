// Name: Header5.h
// Author: Young Lin - chih-yang.l@wustl.edu; Ajay Gupta - a.v.gupta@wustl.edu
// Function : This file contains the enums for Lab 5

#pragma once


enum successAndFailure {
	Success = 0,
	quit = -10,
	not_added_to_file_system = -20, //file was created successfully but was not added to the filesystem correctly
	create_file_error = -30,
	fail_write = -40,
	fail_append = -50,
	file_already_exists = -60,
	nullptr_AbstractFile = -70,
	file_not_open = -80,
	file_opened = -90,
	file_DNE = -100,
	incorrect_password = -110,
	corrupt_file_error = -130,
	append_not_supported = -140,
	size_mismatch = -150,
	invalid_pixel = -160,
	add_command_failure = -170,
	commandPrompt_input_failure = -180,
	file_removal_failure = -190,
	file_cannot_open = -200, 
	file_cannot_clone = -210,
	getline_error = -220,
	catFailed = -230, 
	cpFailed = 240
};

enum magicNumbers {
	maxFileLength = 20,
};