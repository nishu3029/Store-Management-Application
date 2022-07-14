#include "Store.h"

void Store::launch()
{
	loadData();
	long long int choice;

	do {
		std::cout << "\nWelcome to Store Management Interface\n";
		std::cout << "---------------------------------------\n";

		std::cout << "Choose one of below options\n\n";
		std::cout << "1. Login as an Admin\n";
		std::cout << "2. Login as a Store Representative\n";
		std::cout << "Enter any other number to exit\n";

		std::cout << "Enter your choice : ";
		std::string temp;
		std::cin >> temp;
		if (temp == "1" || temp == "2") {
			choice = stoll(temp);
		}
		else {
			choice = 3;
		}

		if (choice == 1) {

			std::string username, password;
			std::cout << "Enter Admin Username : ";
			std::cin >> username;
			std::cout << "Enter Admin Password : ";
			std::cin >> password;
		
			Admin admin(username);
			if (!admin.doAuthentication(password)) {
				continue;
			}
			std::cout << "\nLogged in Successfully as an Admin\n";
			adminOperation(admin);

		}
		else if (choice == 2) {
			std::string username, password;
			std::cout << "Enter Store Representative Username : ";
			std::cin >> username;
			std::cout << "Enter Store Representative Password : ";
			std::cin >> password;

			StoreRep storeRep(username);
			if (!storeRep.doAuthentication(password)) {
				continue;
			}
			std::cout << "\nLogged in Successfully as a Store Representative\n";
			storeRepOperation();
		}
	} while (choice == 1 || choice == 2);

	std::cout << "Successfully Exited\n";
}

void Store::loadData()
{
	loadProductsData();
	loadCustomersData();
}

void Store::loadProductsData()
{
	FileRead fileReader;
	std::vector<std::string> productsList = fileReader.fileTextToStringList("ProductsData/ProductsMetaData.txt");
	for (int i = 0; i < productsList.size(); i++) {
		Product tempProduct(productsList[i]);
		if (!tempProduct.isProductAlreadyExisting())
			continue;
		tempProduct.fetchDetails();
		m_ProductsData[productsList[i]] = tempProduct;
	}
}

void Store::loadCustomersData()
{
	FileRead fileReader;
	std::vector<std::string> customersList = fileReader.fileTextToStringList("CustomersData/CustomersMetaData.txt");
	for (int i = 0; i < customersList.size(); i++) {
		 long long int contactNumber = std::stoll(customersList[i]);
		Customer tempCustomer(contactNumber);
		tempCustomer.fetchDetails();
		if (!tempCustomer.isCustomerRegistered())
			continue;
		m_CustomersData[contactNumber] = tempCustomer;
	}
}

void Store::adminOperation(Admin &admin)
{
	long long int choice;
	do {
		std::cout << "\n\nSelect what you want to do\n\n";
		std::cout << "1. Add a new Store Representative\n";
		std::cout << "2. Check if Store Representative already exists\n";
		std::cout << "3. Add a New Product\n";
		std::cout << "4. Remove a Product\n";
		std::cout << "5. Increase Product Quantity\n";
		std::cout << "6. Get a Product's Details\n";
		std::cout << "7. Get a Customer's Details\n";
		std::cout << "8. Generate Customers Report\n";
		std::cout << "9. Generate Available Products Report\n";
		std::cout << "10. Generate Bills of a Date Report\n";
		std::cout << "Enter any other number to log out\n";

		std::cout << "\nEnter your choice: ";
		std::string temp;
		std::cin >> temp;
		if (areAllCharacterDigits(temp) && temp.length() <= 2) {
			choice = stoll(temp);
		}
		else {
			choice = 11;
		}
		switch (choice)
		{
		case 1:
			addNewStoreRep(admin);
			break;

		case 2:
			checkStoreRepExists(admin);
			break;

		case 3:
			addNewProduct();
			break;

		case 4:
			removeProduct();
			break;

		case 5:
			increaseProductQuantity();
			break;

		case 6:
			getProductDetails();
			break;

		case 7:
			getCustomerDetails();
			break;

		case 8:
			generateCustomersReport();
			break;

		case 9:
			generateAvailableProductReport();
			break;

		case 10:
			generateBillsOfADateReport();
			break;
		default:
			std::cout << "Logging Out ...\n\n";
			break;
		}

	} while (choice >= 1 && choice <= 10);
}

void Store::storeRepOperation()
{
	long long int choice;
	do {
		std::cout << "\n\nSelect what you want to do\n\n";
		std::cout << "1. Take Order and make a bill\n";
		std::cout << "2. Check if customer is registered already\n";
		std::cout << "3. Register a new customer\n";
		std::cout << "4. Change customer membership type\n";
		std::cout << "5. Get a Product's Details\n";
		std::cout << "6. Get a Customer's Details\n";
		std::cout << "7. Generate Customers Report\n";
		std::cout << "8. Generate Available Products Report\n";
		std::cout << "9. Generate Bills of a Date Report\n";
		std::cout << "Enter any other number to log out\n";

		std::cout << "\nEnter your choice: ";
		std::string temp;
		std::cin >> temp;
		if (areAllCharacterDigits(temp) && temp.length() == 1) {
			choice = stoll(temp);
		} else {
			choice = 10;
		}

		switch (choice)
		{
		case 1:
			takeOrderAndMakeBill();
			break;

		case 2: {
			std::cout << "Enter Customer Contact Number : ";
			long long int contactNumber;
			std::cin >> temp;
			if (areAllCharacterDigits(temp) && temp.length() == 10) {
				contactNumber = stoll(temp);
			}
			else {
				std::cout << "You entered a invalid contact Number\n";
				break;
			}
			if (checkCustomerExists(contactNumber)) {
				std::cout << "Yes, customer is already registered\n";
			}
			else {
				std::cout << "No, customer is not registered\n";
			}
			break;
		}
		case 3: {
			std::cout << "Enter a 10-digit Customer Contact Number : ";
			long long int contactNumber;
			std::cin >> temp;
			if (areAllCharacterDigits(temp) && temp.length() == 10) {
				contactNumber = stoll(temp);
			}
			else {
				std::cout << "You entered a invalid contact Number\n";
				break;
			}
			addNewCustomer(contactNumber);
			break;
		}
		case 4: {
			std::cout << "Enter a 10-digit Customer Contact Number : ";
			long long int contactNumber;
			std::cin >> temp;
			if (areAllCharacterDigits(temp) && temp.length() == 10) {
				contactNumber = stoll(temp);
			}
			else {
				std::cout << "You entered a invalid contact Number\n";
				break;
			}
			changeCustomerMembership(contactNumber);
			break;
		}
		case 5:
			getProductDetails();
			break;

		case 6:
			getCustomerDetails();
			break;

		case 7:
			generateCustomersReport();
			break;

		case 8:
			generateAvailableProductReport();
			break;

		case 9:
			generateBillsOfADateReport();
			break;
		default:
			std::cout << "Logging Out ...\n\n";
			break;
		}

	} while (choice >= 1 && choice <= 9);

}

void Store::addNewStoreRep(Admin &admin)
{

	std::cout << "Enter new Store Representative Username : ";
	std::string username, password;
	std::cin >> username;
	std::cout << "Enter new Store Representative password : ";
	std::cin >> password;

	admin.addStoreRep(username, password);
}

void Store::checkStoreRepExists(Admin &admin)
{
	std::cout << "Enter Store Representative Username : ";
	std::string username;
	std::cin >> username;

	if (admin.isStoreRepPresent(username)) {
		std::cout << "Yes, this username already exists\n";
	}
	else {
		std::cout << "No, this username doesn't exist\n";
	}
}

void Store::addNewProduct()
{
	std::cout << "Enter the product model : ";
	std::string productModel;
	std::cin >> productModel;
	Product product(productModel);

	try {
		if (m_ProductsData.find(productModel) != m_ProductsData.end()) {
			//std::cout << "Error : Product Model already exists\n";
			std::string errDescription = "Product Model already exists";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}
	
	std::cout << "Enter product price : ";
	long long int price;
	std::string temp;
	std::cin >> temp;
	if (areAllCharacterDigits(temp) && temp.length() <= 9) {
		price = stoll(temp);
	}
	else {
		std::cout << "You entered a invalid price\n";
		return ;
	}
	std::cout << "Enter Quantity of product : ";
	long long int quantity; 
	std::cin >> temp;
	if (areAllCharacterDigits(temp) && temp.length() <= 9) {
		quantity = stoll(temp);
	}
	else {
		std::cout << "You entered a invalid quantity\n";
		return;
	}
	std::cout << "Enter product's category : ";
	std::string category; std::cin >> category;

	product.addNewProduct(price, quantity, category);
	m_ProductsData[productModel] = product;
}

void Store::removeProduct()
{
	std::cout << "Enter the product model you want to remove : ";
	std::string productModel;
	std::cin >> productModel;
	Product product(productModel);
	product.deleteProduct();
	m_ProductsData.erase(productModel);
}

void Store::increaseProductQuantity()
{
	std::cout << "Enter the product model : ";
	std::string productModel;
	std::cin >> productModel;
	Product product(productModel);

	try {
		if (m_ProductsData.find(productModel) == m_ProductsData.end()) {
			//std::cout << "Error : Product Model doesn't exist\n";
			//std::cout << "Please add this model using \"Add a new product\" option\n";
			std::string errDescription = "Product Model doesn't exist\nPlease add this model using \"Add a new product\" option\n";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}

	std::cout << "Enter how much quantity you want to add : ";
	std::string temp;
	long long int quantity;
	std::cin >> temp;
	if (areAllCharacterDigits(temp) && temp.length() <= 9) {
		quantity = stoll(temp);
	}
	else {
		std::cout << "You entered invalid quantity\n";
		return;
	}
	
	product = m_ProductsData[productModel];
	product.increaseQuanityBy(quantity);
	m_ProductsData[productModel] = product;
	std::cout << "Successfully, updated the Product Quantity\n";
}

void Store::getProductDetails()
{
	std::cout << "Enter the product model : ";
	std::string productModel;
	std::cin >> productModel;
	try {
		if (m_ProductsData.find(productModel) == m_ProductsData.end()) {
			//std::cout << "Error : Product Model doesn't exist\n";
			std::string errDescription = "Product Model doesn't exist";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}

	std::cout << "Product Model : " << productModel << "\n";
	std::cout << "Product Price : " << m_ProductsData[productModel].getPrice() << "\n";
	std::cout << "Product Category : " << m_ProductsData[productModel].getCategory() << "\n";
	std::cout << "Product Quantity Available : " << m_ProductsData[productModel].getQuantity() << "\n";
	
}

void Store::getCustomerDetails()
{
	std::cout << "Enter a 10-digit Customer Contact Number : ";
	 long long int contactNumber; std::string temp; std::cin >> temp;
	if (areAllCharacterDigits(temp) && temp.length() == 10) {
		contactNumber = stoll(temp);
	}
	else {
		std::cout << "You entered a invalid contact Number\n";
		return ;
	}

	try {
		if (m_CustomersData.find(contactNumber) == m_CustomersData.end()) {
			//std::cout << "Customer with contact number : " + std::to_string(contactNumber) + " doesn't exist\n";
			std::string errDescription = "Customer with contact number : " + std::to_string(contactNumber) + " doesn't exist\n";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}

	std::cout << "Customer Name : " << m_CustomersData[contactNumber].getName() << "\n";
	std::cout << "Customer Address : " << m_CustomersData[contactNumber].getAddress() << "\n";
	std::cout << "Customer Contact Number : " << std::to_string(contactNumber) << "\n";
	std::cout << "Customer Membership Type : " << m_CustomersData[contactNumber].getMembershipType() << "\n";

}

void Store::generateCustomersReport()
{
	Report reportObject;
	reportObject.generateCustomersReport();
	std::cout << "Successfully generated registered and unregistered customers report\n";
	std::cout << "Reports are saved in Reports directory\n";
}

void Store::generateAvailableProductReport()
{
	Report reportObject;
	reportObject.generateProductsAvailableReport();
	std::cout << "Successfully generated available products report\n";
	std::cout << "Reports are saved in Reports directory\n";
}

void Store::generateBillsOfADateReport()
{
	std::cout << "Example for entering date : Jun-05-2022, Jul-15-2022 \n";
	std::cout << "Enter date(in Mmm-DD-YYYY format) you want the report for : ";
	std::string date; std::cin >> date;
	Report reportObject;
	reportObject.generateBillsOnADate(date);
	std::cout << "Successfully generated bills of a date report\n";
	std::cout << "Reports are saved in Reports directory\n";
}

void Store::takeOrderAndMakeBill()
{
	std::cout << "Enter a 10-digit Customer Contact Number : ";
	 long long int contactNumber; std::string temp;  std::cin >> temp;
	if (areAllCharacterDigits(temp) && temp.length() == 10) {
		contactNumber = stoll(temp);
	}
	else {
		std::cout << "You entered a invalid contact Number\n";
		return ;
	}

	try {
		if (!checkCustomerExists(contactNumber)) {
			std::string errDescription = "Customer with contact number : " + std::to_string(contactNumber) + " doesn't exist";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		std::cout << "Please Register the customer using \"Register a new customer\" Option\n";
		return;
	}
	Shopping cart;
	std::string productModel;
	std::string checker;
	do {
		std::cout << "Enter the product model you want to add to cart or (EXIT) to checkout the cart: ";
		std::cin >> productModel;
		checker = productModel;
		std::transform(checker.begin(), checker.end(), checker.begin(), ::tolower);
		if (checker == "exit")
			break;

		std::cout << "Enter the quantity you want to buy : ";
		 long long int quantity; std::string temp; std::cin >> temp;
		if (areAllCharacterDigits(temp) && temp.length() <= 9) {
			quantity = stoll(temp);
		}
		else {
			std::cout << "You entered invalid quantity\n";
			break;
		}
		if (cart.addToCart(productModel, quantity)) {
			m_ProductsData[productModel].decreaseQuantityBy(quantity);
		}
	} while (checker != "exit");

	Bill bill(m_CustomersData[contactNumber], cart);
	std::cout << "Generating the bill........\n";
	bill.generateBill();
	std::cout << "Bill generated successfully........\n";
}

bool Store::checkCustomerExists(const long long int contactNumber)
{
	if (m_CustomersData.find(contactNumber) == m_CustomersData.end()) {
		return false;
	}
	else {
		return true;
	}
}

void Store::addNewCustomer(const long long int contactNumber)
{
	try {
		if (checkCustomerExists(contactNumber)) {
			std::string errDescription = "Customer with contact number : " + std::to_string(contactNumber) + " already exists";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}

	std::string name, address, membershipType;
	std::cout << "Enter Customer Name : ";
	std::cin >> name;

	std::cout << "Enter Customer Address: ";
	std::cin >> address;

	std::cout << "Choose the new membership Type\n";
	std::cout << "1. CLASSIC\n";
	std::cout << "2. PREMIUM\n";
	std::cout << "3. GOLD\n";
	std::cout << "Any other number if not interested in membership \n";
	std::cout << "Enter choice: ";
	
	long long int choice; std::string temp; std::cin >> temp;
	
	if (areAllCharacterDigits(temp) && temp.length() == 1) {
		choice = stoll(temp);
	}
	else {
		choice = 4;
	}
	if (choice == 1)
		membershipType = "CLASSIC";
	else if (choice == 2)
		membershipType = "PREMIUM";
	else if (choice == 3)
		membershipType = "GOLD";
	else
		membershipType = "NONE";

	Customer newCustomer(name, contactNumber, address, membershipType);
	newCustomer.registerCustomer(name,address,membershipType);
	m_CustomersData[contactNumber] = newCustomer;

	std::cout << "Successfully registered the customer\n";
}

void Store::changeCustomerMembership(const long long int contactNumber)
{
	try {
		if (!checkCustomerExists(contactNumber)) {
			std::string errDescription = "Customer with contact number : " + std::to_string(contactNumber) + " doesn't exists";
			throw Exception(errDescription, __func__, __FILE__, __LINE__);
		}
	} catch (Exception& exception) {
		std::cout << exception.getErrorDescription() << "\n";
		return;
	}
	std::cout << "Choose the new membership Type\n";
	std::cout << "1. CLASSIC\n";
	std::cout << "2. PREMIUM\n";
	std::cout << "3. GOLD\n";
	std::cout << "Any other number if not interested in membership\n";
	std::cout << "Enter choice: ";
	long long int choice; std::string temp;  std::cin >> temp;
	if (areAllCharacterDigits(temp) && temp.length() == 1) {
		choice = stoll(temp);
	}
	else {
		choice = 4;
	}
	std::string type;
	if (choice == 1)
		type = "CLASSIC";
	else if (choice == 2)
		type = "PREMIUM";
	else if (choice == 3)
		type = "GOLD";
	else
		type = "NONE";
	m_CustomersData[contactNumber].changeMembershipType(type);
	std::cout << "Successfully updated the membership type\n";
}

bool Store::areAllCharacterDigits(const std::string &choice) {
	
	if (choice.length() == 0) {
		return false;
	}

	for (int i = 0; i < choice.length(); i++) {
		if (choice[i] >= '0' && choice[i] <= '9')
			continue;
		else
			return false;
	}
	return true;
}