#include "Admin.h"

Admin::Admin(const std::string &username) : User(username)
{
}

bool Admin::doAuthentication(const std::string &password) 
{
    FileRead fileReader;
    
    bool check =  fileReader.checkAdminPassword(m_Username, password);
    try {
        if (!check) {
            std::string errDescription = "Wrong Admin Credentials entered";
            throw Exception(errDescription, __func__, __FILE__, __LINE__);
        }
    }
    catch (Exception& exception) {
        std::cout << exception.getErrorDescription() << "\n";
        return check;
    }
    return check;
}

void Admin::addStoreRep(const std::string &username, const std::string &password)
{
    try {
        if (isStoreRepPresent(username)) {
            //std::cout << "Store Representative with username : " << username << " already exists\n";
            std::string errDescription = "Store Representative with username : " + username + " already exists ";
            throw Exception(errDescription, __func__, __FILE__, __LINE__);
        }
    } catch (Exception& exception) {
        std::cout << exception.getErrorDescription() << "\n";
        return;
    }
    FileWrite fileWriter;
    fileWriter.makeNewStoreRep( username, password);
    std::cout << "StoreRepresentive successfully registered\n";
}

bool Admin::isStoreRepPresent(const std::string &username)
{
    FileRead fileReader;
    std::string path = "UserData/StoreRep/" + username + ".txt";
    return fileReader.checkFileExists(path);
}
