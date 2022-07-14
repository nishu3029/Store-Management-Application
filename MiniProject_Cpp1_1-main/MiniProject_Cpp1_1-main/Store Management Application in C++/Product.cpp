#include "Product.h"

Product::Product(const std::string &model) : m_ProductModel{model}
{

}

Product::Product(const std::string &model, const long long int price, const long long int quantity, const std::string &category) :
    m_ProductModel{model},
    m_Price{price},
    m_Quantity{quantity},
    m_Category{category}
{

}

std::string Product::getProductModel()
{
    return m_ProductModel;
}

long long int Product::getPrice()
{
    return m_Price;
}

long long int Product::getQuantity()
{
    return m_Quantity;
}

std::string Product::getCategory()
{
    return m_Category;
}

void Product::increaseQuanityBy(const long long int value)
{
    m_Quantity += value;
    FileWrite fileWriter;
    fileWriter.updateQuantity(m_ProductModel, m_Quantity);
}

void Product::decreaseQuantityBy(const long long int value)
{
    m_Quantity -= value;
    FileWrite fileWriter;
    fileWriter.updateQuantity(m_ProductModel, m_Quantity);
}

void Product::addNewProduct(const long long int price, const long long int quantity, const std::string &category)
{
    FileWrite fileWriter;
    m_Price = price;
    m_Quantity = quantity;
    m_Category = category;

    fileWriter.makeNewProduct(m_ProductModel, price, quantity, category);
    std::cout << "Successfully added new product with model name : " + m_ProductModel + "\n";
}

bool Product::isProductAlreadyExisting()
{
    std::string filePath = "ProductsData/" + m_ProductModel + ".txt";
    FileRead fileReader;
    return  fileReader.checkFileExists(filePath);
}

void Product::fetchDetails()
{
    try {
        if (!isProductAlreadyExisting()) {
            std::string errDescription = "Product Model : " + m_ProductModel + " doesn't not exist";
            throw Exception(errDescription, __func__, __FILE__, __LINE__);
        }
    } catch (Exception& exception) {
        std::cout << exception.getErrorDescription() << "\n";
        return;
    }

    FileRead tempFileReader;
    std::vector<std::string > details = tempFileReader.getProductDetails(m_ProductModel);
    m_Price = std::stoll(details[0]);
    m_Quantity = std::stoll(details[1]);
    m_Category = details[2];
}

bool Product::isProductAvailable(const long long int requiredQuantity)
{
    return m_Quantity >= requiredQuantity;
}

void Product::deleteProduct()
{   
    FileWrite fileWriter;
    try {
        if (fileWriter.deleteProductFile(m_ProductModel) != 0) {
            //std::cout << "Such Product doesn't exist\n";
            std::string errDescription = "Such product doesn't exist";
            throw Exception(errDescription, __func__, __FILE__, __LINE__);
        }
    } catch (Exception& exception) {
        std::cout << exception.getErrorDescription() << "\n";
        return;
    }
    std::cout << "Product removed Succesfully\n";
}
