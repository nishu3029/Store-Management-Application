#include "Customer.h"

Customer::Customer()
{
}

Customer::Customer(const long long int contactNumber) : m_ContactNumber{contactNumber}
{
}

Customer::Customer(const std::string &name, const long long int contactNumber, const std::string &address, const std::string &type) :
	m_Name{name},
	m_ContactNumber{contactNumber},
	m_Address{address},
	m_MembershipType{type}
{

}

std::string Customer::getName()
{
	return m_Name;
}

std::string Customer::getAddress()
{
	return m_Address;
}

long long int Customer::getContactNumber()
{
	return m_ContactNumber;
}

std::string Customer::getMembershipType()
{
	return  m_MembershipType;
}

void Customer::registerCustomer(const std::string &name, const std::string &address, const std::string &type)
{
	try {
		if (isCustomerRegistered()) {
			//std::cout << "Customer with this contact number already exists\n";
			std::string errDescription = "Customer with this contact number already exists";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	}
	catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}
	FileWrite tempFileWriter;
	m_Name = name;
	m_Address = address;
	m_MembershipType = type;
	tempFileWriter.makeNewCustomer(name, m_ContactNumber, address,type);
	return;
}

bool Customer::isCustomerRegistered()
{
	std::string fileName = std :: to_string(m_ContactNumber);
	fileName += ".txt";
	std::string filePath = "CustomersData/" + fileName;
	FileRead tempFileReader;
	return tempFileReader.checkFileExists(filePath);

}

void Customer::fetchDetails()
{
	try {
		if (!isCustomerRegistered()) {
			//std::cout << "Customer doesn't exist with this contact Number\n";
			std::string errDescription = "Customer doesn't exist with this contact Number";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	}
	catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}
	FileRead tempFileReader;
	std::vector<std::string > details = tempFileReader.getCustomerDetails(m_ContactNumber);
	m_Name = details[0];
	m_Address = details[1];
	m_MembershipType = details[2];

}

void Customer::changeMembershipType(const std::string &type)
{	
	try {
		if (!isCustomerRegistered()) {
			//std::cout << "Customer doesn't exist with this contact Number\n";
			std::string errDescription = "Customer doesn't exist with this contact Number";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	}
	catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}
	FileWrite tempFileWriter;
	tempFileWriter.updateMembershipType(m_ContactNumber, type);
	m_MembershipType = type;
}
