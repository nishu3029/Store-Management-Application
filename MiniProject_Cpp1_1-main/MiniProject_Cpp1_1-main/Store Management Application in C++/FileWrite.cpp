#include "FileWrite.h"

extern std::map<std::string,  long long int> discountPercentage;

void FileWrite::makeNewStoreRep(const std::string& username, const std::string& password)
{   
    std::string filePath = "UserData/StoreRep/" + username + ".txt";
    std::ofstream outputFile(filePath);
    outputFile << password << "\n";

}

void FileWrite::makeNewCustomer(const std::string& name, const long long int contactNumber, const std::string& address, const std::string& type)
{
    std::string filePath = "CustomersData/" + std::to_string(contactNumber) + ".txt";
    std::ofstream  inputFile(filePath);
    inputFile << name << "\n";
    inputFile << address << "\n";
    inputFile << type << "\n";

    std::ofstream outfile;

    outfile.open("CustomersData/CustomersMetaData.txt", std::ios_base::app); // append instead of overwrite
    outfile << std::to_string(contactNumber) << "\n";

}

void FileWrite::updateMembershipType(const long long int contactNumber, const std::string& type)
{
   
    std::string filePath = "CustomersData/" + std::to_string(contactNumber) + ".txt";
    modifyLine(filePath, 3, type);
}

void FileWrite::makeNewProduct(const std::string& model, const long long int price, const long long int quantity, const std::string& category)
{
    std::string filePath = "ProductsData/" + model + ".txt";
    std::ofstream  inputFile(filePath);
    inputFile << price << "\n";
    inputFile << quantity << "\n";
    inputFile << category << "\n";

    std::ofstream outfile;

    outfile.open("ProductsData/ProductsMetaData.txt", std::ios_base::app); // append instead of overwrite
    outfile << model << "\n";
}

void FileWrite::updateQuantity(const std::string& model, const long long int newQuantity)
{
    std::string filePath = "ProductsData/" + model + ".txt";
    modifyLine(filePath, 2, std::to_string(newQuantity));
}

 long long int FileWrite::deleteProductFile(const std::string& model)
{
    std::string filePath = "ProductsData/" + model + ".txt";
    std::ifstream input("ProductsData/ProductsMetaData.txt");
    std::string temp,updatedMetaData = "";

    while (std::getline(input, temp)) {
        if (temp != model)
            updatedMetaData += temp + "\n";
    }
    std::ofstream output("ProductsData/ProductsMetaData.txt");

    output << updatedMetaData;

    return remove(filePath.c_str());
}

void FileWrite::makeBillFile(const std::string& dateAndTime, const long long int customerContactNumber, const std::string& Summary, const long long int totalPrice, const double discountedPrice)
{
    std::string filePath = "BillsData/" + dateAndTime + ".txt";

    std::cout << filePath << "\n";
    std::ofstream  inputFile(filePath);

    inputFile << "Date : " << dateAndTime << "\n";
    inputFile <<  "Customer Contact Number : " << std::to_string(customerContactNumber) << "\n\n";
    inputFile << "Product Model" << "\t" << "Quantity" << "\t" << "Price (per 1 piece)" << "\n";
    inputFile << Summary << "\n"; //There should not be "\n" here
    inputFile << "Total Price : " << std::to_string(totalPrice) << "\n";
    inputFile << "Discounted Price : " << std::to_string(discountedPrice) << "\n";

    std::ofstream outfile;

    outfile.open("BillsData/BillsMetaData.txt", std::ios_base::app); // append instead of overwrite
    outfile << dateAndTime << "\n";
}

void FileWrite::makeCustomerReport()
{
    std::ifstream metaData("CustomersData/CustomersMetaData.txt");
    std::ofstream registeredCustomersReport("Reports/RegisteredCustomersReport.txt");
    std::ofstream unregisteredCustomersReport("Reports/UnregisteredCustomersReport.txt");

    registeredCustomersReport << "Customer Name" << "\t\t\t" << "Contact Number" << "\t\t\t" << "Membership Type" << "\n";
    unregisteredCustomersReport << "Customer Name" << "\t\t\t" << "Contact Number" << "\n";


    std::string tempString;
    while (std::getline(metaData, tempString)) {
         long long int contactNumber = std::stoll(tempString);
        FileRead  fileReader;

        std::vector<std::string> customerDetails = fileReader.getCustomerDetails(contactNumber);
        if (customerDetails[2] == "NONE") {
            unregisteredCustomersReport << customerDetails[0] << "\t\t\t\t\t\t" << tempString << "\n";
        }
        else {
            registeredCustomersReport << customerDetails[0] << "\t\t\t" << tempString << "\t\t\t" << customerDetails[2] << "\n";
        }
    }
}

void FileWrite::makeBillsOnADateReport(const std::string& date)
{
    std::ifstream metaData("BillsData/BillsMetaData.txt");
    std::ofstream billsOfADateReport("Reports/BillsOf" + date + "Report.txt");

    billsOfADateReport << "Bill-Id" << "\t\t\t" << "Customer Contact Number" << "\t\t\t" << "Price Paid\n";

    std::string billId;
    while (std::getline(metaData, billId)) {
        FileRead fileReader;
        std::vector<std::string> billDetails = fileReader.getBillDetails(billId);
        if (billDetails[0] == date) {
            billsOfADateReport << billId << "\t\t\t" << billDetails[1] << "\t\t\t" << billDetails[2] << "\n";
        }
    }
}

void FileWrite::makeAvailableProductsReport()
{
    std::ifstream metaData("ProductsData/ProductsMetaData.txt");
    std::ofstream avaiableProductsReport("Reports/AvaiableProductsReport.txt");

    avaiableProductsReport << "Product Model" << "\t\t\t" << "Avaialable Quantity\n";

    std::string modelName;
    while (std::getline(metaData, modelName)) {
        
        FileRead  fileReader;

        std::vector<std::string> productDetails = fileReader.getProductDetails(modelName);

        if (productDetails.size() > 0 && std::stoll(productDetails[1]) > 0) {
            avaiableProductsReport << modelName << "\t\t\t\t\t" << productDetails[1] << "\n";
        }
    }
}


void FileWrite::modifyLine(const std::string& filePath, const long long int lineNo, const std::string& newText)
{
    std::ifstream inputFile(filePath);
    std::string fileContent{ "" }, temp;

     long long int lineCount = 1;
    
    while (getline(inputFile, temp)) {
        if (lineCount == lineNo) {
            fileContent += ( newText + "\n");
        }
        else {
            fileContent += (temp + "\n");
        }
        ++lineCount;
    }

    std::ofstream outputFile(filePath);
    outputFile << fileContent;   
}


