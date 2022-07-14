#include "Bill.h"


extern std::map<std::string, long long int> discountPercentage;


Bill::Bill(Customer &customer, Shopping &cart):
	m_Customer{customer},
	m_Cart{cart}
{
	m_TotalPrice = cart.getTotalPrice();
	m_DiscountedPrice = 1.0 * m_TotalPrice  * ( 100 - discountPercentage[customer.getMembershipType()]) / 100.0;
}

void Bill::generateBill()
{
	const long long int customerContactNumber = m_Customer.getContactNumber();
	std::string summary = m_Cart.getSummary();

	m_DateAndTime = getDateAndTime();

	std::cout << m_DateAndTime << " is the time\n";

	FileWrite fileWriter;
	fileWriter.makeBillFile(m_DateAndTime, customerContactNumber, summary, m_TotalPrice, m_DiscountedPrice);

	std::vector <std::string> productModelsList = m_Cart.getProductModelsList();
	std::vector<long long int> quantities = m_Cart.getQuantities();

	try {
		if (productModelsList.size() == 0) {
			std::string errDescription = "Empty cart";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}
}

std::string Bill::getDateAndTime()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	const int MAXLEN = 80;
	char s[MAXLEN];
	time_t t = time(0);
	strftime(s, MAXLEN, "%b-%d-%Y-%H-%M-%S", &newtime);
	std::string temp(s);
	return temp;
}
