#pragma once
#include<map>
#include<cstdio>
#include"FileRead.h"

class FileWrite
{
public:

	void makeNewStoreRep(const std::string &username, const std::string &password);
	void makeNewCustomer(const std::string &name,  const long long int contactNumber, const std::string &address, const std::string &type);
	void updateMembershipType(const long long int contactNumber, const std::string &type);
	void makeNewProduct(const std::string &model,  const long long int price, const long long int quantity, const std::string &category);
	void updateQuantity(const std::string &model,  const long long int newQuantity);
	long long int deleteProductFile(const std::string &model);
	void makeBillFile(const std::string &dateAndTime, const long long int customerContactNumber, const std::string &Summary, const long long int totalPrice, const double discountedPrice);
	void makeCustomerReport();
	void makeBillsOnADateReport(const std::string &date);
	void makeAvailableProductsReport();
	void modifyLine(const std::string &filePath, const long long int lineNo, const std::string &newText);
};

