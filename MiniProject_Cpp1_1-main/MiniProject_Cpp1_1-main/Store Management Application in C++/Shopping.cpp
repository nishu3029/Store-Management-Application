#include "Shopping.h"

std::vector<std::string> Shopping::getProductModelsList()
{
	return m_ProductModels;
}

std::vector<long long int> Shopping::getQuantities()
{
	return m_Quantities;
}

long long int Shopping::getTotalPrice()
{
	return m_TotalPrice;
}

std::string Shopping::getSummary()
{
	return m_Summary;
}

bool Shopping::addToCart(const std::string &productModel, const long long int quantity)
{
	Product tempProduct{ productModel };
	try {
		if (!tempProduct.isProductAlreadyExisting()) {
			//std::cout << "Product Not Available at Store\n";
			std::string errDescription = "Product Model : " + productModel + " not available at the store";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return false;
	}
	tempProduct.fetchDetails();

	try {
		if (!tempProduct.isProductAvailable(quantity)) {
			//std::cout << "Sorry that much quantity is not available\n";
			std::string errDescription = "Sorry that much quantity is not available at the store";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return false;
	}

	// Reduce the quantity after billing
	m_ProductModels.push_back(productModel);
	m_Quantities.push_back(quantity);

	long long int productPrice = tempProduct.getPrice();
	m_TotalPrice += quantity * productPrice;
	m_Summary += productModel + "\t\t\t" + std::to_string(quantity) + "\t\t" + std::to_string(productPrice)+"\n";
	return true;
}
