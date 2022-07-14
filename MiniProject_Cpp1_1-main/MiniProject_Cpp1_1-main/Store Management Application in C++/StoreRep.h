#pragma once
#include<iostream>
#include "User.h"
#include "FileRead.h"
#include "FileWrite.h"

class StoreRep : public User
{
	
public:
	StoreRep(const std::string &username);
	bool doAuthentication(const std::string &password) override;
};

