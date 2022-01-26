#ifndef ENHANCEDUSERSYSTEM_USERPAGE_H
#define ENHANCEDUSERSYSTEM_USERPAGE_H
#include "Encryption.h"
#include "ProfileData.h"
#include <filesystem>

class UserPage {
private:
    string Username;
    string Password;
    string Email;

    string users;

    void personalDetails();
    void displayData();

public:
    explicit UserPage(string username);
    void userMenu();
    void changeData();
    void changeUsername(const string& newUsername);

    void changePassword();
    void changeEmail();

    ~UserPage();
};


#endif //ENHANCEDUSERSYSTEM_USERPAGE_H
