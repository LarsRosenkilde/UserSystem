#ifndef ENHANCEDUSERSYSTEM_USERPAGE_H
#define ENHANCEDUSERSYSTEM_USERPAGE_H
#include "Encryption.h"
#include "ProfileData.h"

class UserPage {
private:
    string Username;
    string Password;
    string Email;
    string FirstName;
    string LastName;
    string Gender;
    string Age;
    string Height;
    string Weight;
    string Bmi;

    int age{};
    double height{};
    double weight{};

    string users;

    string newData;
    string newHeight;
    string newWeight;
    string newBmi;

    void personalDetails();
    void displayData();

public:
    explicit UserPage(string username);
    void userMenu();
    void changeData();
    ~UserPage();
};


#endif //ENHANCEDUSERSYSTEM_USERPAGE_H
