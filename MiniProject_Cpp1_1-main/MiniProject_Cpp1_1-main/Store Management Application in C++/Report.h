#pragma once
#include "FileWrite.h"

class Report
{
public:
	void generateProductsAvailableReport();
	void generateCustomersReport();
	void generateBillsOnADate(const std::string &date);
};

