#pragma once
#include<exception>
#include<string>
#include <ostream>
class Exception : public std::exception
{
	std::string description{};
	std::string functionName{};
	std::string fileName{};
	long long int lineNumber{};

public : 
	Exception(std::string description, std::string funName, std::string filename,  long long int lineNum) :
		description{ description }, functionName{ funName }, fileName{ filename }, lineNumber{ lineNum } {
	}
	const std::string getSourceFileName() const;
	const std::string getfunctionName() const;
	const std::string getErrorDescription() const;
	long long int getExceptionLineNumber() const;
	void printExceptionDetails();
};