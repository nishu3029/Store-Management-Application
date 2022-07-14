#pragma once
#include<iostream>
#include "User.h"
#include "FileWrite.h"

class Admin : public User
{
public:
	Admin() = delete;
	Admin(const Admin &admin) = delete;
	Admin(const std::string &username);
	bool doAuthentication(const std::string &password) override;
	void addStoreRep(const std::string &username, const std::string &password);
	bool isStoreRepPresent(const std::string &username);
};

