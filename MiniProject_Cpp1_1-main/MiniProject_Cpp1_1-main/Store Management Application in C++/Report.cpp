#include "Report.h"

void Report::generateProductsAvailableReport()
{
	FileWrite fileWriter;
	fileWriter.makeAvailableProductsReport();
}

void Report::generateCustomersReport()
{
	FileWrite fileWriter;
	fileWriter.makeCustomerReport();
}

void Report::generateBillsOnADate(const std::string &date)
{
	FileWrite fileWriter;
	fileWriter.makeBillsOnADateReport(date);
}
