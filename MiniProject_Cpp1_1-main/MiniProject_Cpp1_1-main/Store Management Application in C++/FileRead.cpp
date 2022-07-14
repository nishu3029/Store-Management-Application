#include "FileRead.h"

bool FileRead::checkPassword(const std::string& filePath, const std::string& password)
{
    std::ifstream f(filePath.c_str());
    if (f.good()) {
        std::string temp;
        std::getline(f, temp);
        return (temp == password);
    }
    else 
        return false;
}

bool FileRead::checkAdminPassword(const std::string& username, const std::string& password)
{
    std::string filePath = "UserData/Admin/" + username + ".txt";
    return checkPassword(filePath, password);
}

bool FileRead::checkStoreRepPassword(const std::string& username, const std::string& password)
{
    std::string filePath = "UserData/StoreRep/" + username + ".txt";
    return checkPassword(filePath, password);
}

bool FileRead::checkFileExists(const std::string& path)
{
    std :: ifstream f(path.c_str()); return f.good();

}

std::vector<std::string> FileRead::getCustomerDetails(const long long int contactNumber)
{
    std::string filePath = "CustomersData/" + std::to_string(contactNumber) + ".txt";
    return fileTextToStringList(filePath);
}

std::vector<std::string> FileRead::getProductDetails(const std::string& productModel)
{
    std::string filePath = "ProductsData/" + productModel + ".txt";
    return fileTextToStringList(filePath);
}

std::vector<std::string> FileRead::getBillDetails(const std::string& billId)
{
    std::string filePath = "BillsData/" + billId + ".txt";
    std::vector<std::string> details;
    std::ifstream billData(filePath);

    std::string temp;

    std::getline(billData, temp);
    temp = temp.substr(7, 11);
    details.push_back(temp);

    std::getline(billData, temp);
    temp = temp.substr(26);
    details.push_back(temp);

    std::string temp2;
    while(std::getline(billData, temp2)){
        temp = temp2;
    }

    temp = temp.substr(19);
    details.push_back(temp);

    return details;
}

std::string FileRead::getLineFromFile(const long long int lineNo, const std::string& filePath)
{
    return fileTextToStringList(filePath)[lineNo - 1];
}

std::vector<std::string> FileRead::fileTextToStringList(const std::string& filePath)
{
    std::ifstream  inputFile(filePath);

    std::vector < std::string > output;
    std::string temp;
    while (std::getline(inputFile, temp)) {
        output.push_back(temp);
    }
    return output;
}
