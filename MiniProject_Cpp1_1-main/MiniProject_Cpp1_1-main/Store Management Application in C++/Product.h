#pragma once
#include "FileWrite.h"

class Product
{
	std::string m_ProductModel{};
	long long int m_Price{};
	long long int m_Quantity{};
	std::string m_Category{};

public:
	Product() {}
	Product(const std::string &model);
	Product(const std::string &model, const long long int price, const long long int quantity, const std::string &category);

	std::string getProductModel();
	long long int getPrice();
	long long int getQuantity();
	std::string	getCategory();

	void increaseQuanityBy(const long long int value);
	void decreaseQuantityBy(const long long int value);
	void addNewProduct(const long long int price, const long long int quantity, const std::string &category);
	bool isProductAlreadyExisting();
	void fetchDetails();
	bool isProductAvailable(const long long int requiredQuantity);
	void deleteProduct();
};

