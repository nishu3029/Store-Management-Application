#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "Exception.h"

class FileRead
{
public:
	bool checkPassword(const std::string &filePath, const std::string &password);
	bool checkAdminPassword(const std::string &username, const std::string &password);
	bool checkStoreRepPassword(const std::string &username, const std::string &password);

	bool checkFileExists(const std::string &path);
	std::vector<std::string> getCustomerDetails(const long long int contactNumber);
	std::vector<std::string> getProductDetails(const std::string &productModel);
	std::vector<std::string> getBillDetails(const std::string &billId);

	std::string getLineFromFile(const long long int lineNo, const std::string &filePath);
	std::vector<std::string> fileTextToStringList(const std::string &filePath);
};

