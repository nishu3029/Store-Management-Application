#pragma once
#include<iostream>
class User
{
protected:
	std::string m_Username;
public:
	
	User(std::string username);
	virtual ~User() {}
	virtual bool doAuthentication(const std::string &password) = 0;
	
};

