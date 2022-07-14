#pragma once
#include "Product.h"
class Shopping
{
	std::vector<std::string> m_ProductModels{};
	std::vector< long long int> m_Quantities{};
	long long int m_TotalPrice{};
	std::string m_Summary{};

public:
	std::vector<std::string> getProductModelsList();
	std::vector<long long int> getQuantities();
	long long int getTotalPrice();
	std::string getSummary();
	bool addToCart(const std::string &productModel, const long long int quantity);
};

