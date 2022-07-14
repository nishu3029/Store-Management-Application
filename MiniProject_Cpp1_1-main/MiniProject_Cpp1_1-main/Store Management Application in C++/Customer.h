#pragma once
#include "FileWrite.h"
class Customer
{
	std::string m_Name{"N/A"};
	long long int m_ContactNumber{};
	std::string m_Address{"N/A"};
	std::string m_MembershipType{"NONE"}; 
public:
	Customer();
	Customer(const long long int contactNumber);
	Customer(const std::string &name, const long long int contactNumber, const std::string &address, const std::string &type);
	std::string getName();
	std::string getAddress();
	long long int getContactNumber();
	std::string getMembershipType();
	void registerCustomer(const std::string &name, const std::string &address, const std::string &type);
	bool isCustomerRegistered();
	void fetchDetails();
	void changeMembershipType(const std::string &type);
};

