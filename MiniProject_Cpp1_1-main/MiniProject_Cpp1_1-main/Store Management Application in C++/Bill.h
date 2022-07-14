#pragma once
#include "Customer.h"
#include "Shopping.h"
#include<cmath>
#include<sstream>
#include<ctime>

class Bill
{
	Customer m_Customer;
	Shopping m_Cart;
	long long int m_TotalPrice;
	double m_DiscountedPrice;
	std::string m_DateAndTime{};

public:
	Bill(Customer &customer, Shopping &cart);
	void generateBill();
	std::string getDateAndTime();
};

