#include "StoreRep.h"

StoreRep::StoreRep(const std::string &username): User(username) 
{
}

bool StoreRep::doAuthentication(const std::string &password)
{
	FileRead fileReader;
	bool check = fileReader.checkStoreRepPassword(m_Username, password);
    try {
        if (!check) {
            std::string errDescription = "Wrong Store Representative Credentials entered";
            throw Exception(errDescription, __func__, __FILE__, __LINE__);
        }
    }
    catch (Exception& exception) {
        std::cout << exception.getErrorDescription() << "\n";
        return check;
    }
    return check;
}
