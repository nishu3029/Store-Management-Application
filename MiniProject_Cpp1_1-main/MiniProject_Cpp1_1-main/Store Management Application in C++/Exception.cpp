#include "Exception.h"
#include<iostream>

const std::string Exception::getSourceFileName() const {
	return fileName;
}
const std::string Exception::getfunctionName() const {
	return functionName;
}

const std::string Exception::getErrorDescription() const {
	std::cout << "\nException was thrown with following details : \n";
	return description;
}

 long long int Exception::getExceptionLineNumber() const {
	return lineNumber;
}

void Exception::printExceptionDetails() {

	std::cout << std::endl;
	std::cout << "An Exception was reported/thrown with following details..." << std::endl;
	std::cout << "Function Name---------------" << functionName << std::endl;
	std::cout << "File Name-------------------" << fileName << std::endl;
	std::cout << "Line Number-----------------" << lineNumber << std::endl;
	std::cout << "Description-----------------" << description << std::endl;
	std::cout << std::endl;
}