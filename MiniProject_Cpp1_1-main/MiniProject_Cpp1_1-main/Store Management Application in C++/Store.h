#pragma once
#include "Bill.h"
#include "Report.h"
#include "Admin.h"
#include "StoreRep.h"
#include <map>
#include<algorithm>
class Store
{
	std::map<std::string, Product> m_ProductsData;
	std::map<long long int, Customer> m_CustomersData;

public :
	void launch();
	void loadData();
	void loadProductsData();
	void loadCustomersData();
	void adminOperation(Admin &admin);
	void storeRepOperation();

	void addNewStoreRep(Admin &admin);
	void checkStoreRepExists(Admin &admin);
	void addNewProduct();
	void removeProduct();
	void increaseProductQuantity();
	void getProductDetails();
	void getCustomerDetails();
	void generateCustomersReport();
	void generateAvailableProductReport();
	void generateBillsOfADateReport();

	void takeOrderAndMakeBill();
	bool checkCustomerExists(const long long int contactNumber);
	void addNewCustomer(const long long int contactNumber);
	void changeCustomerMembership(const long long int contactNumber);
	bool areAllCharacterDigits(const std::string &choice);
};

