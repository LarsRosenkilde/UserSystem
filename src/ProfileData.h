#ifndef ENHANCEDUSERSYSTEM_PROFILEDATA_H
#define ENHANCEDUSERSYSTEM_PROFILEDATA_H
#include "Encryption.h"
#include <utility>
#include <cmath>

class ProfileData {
private:
    string Username;
    string Password;
    string Email;
    string Firstname;
    string Lastname;
    string Gender;
    signed int Age{};
    double Height;
    double Weight;
    double Bmi;

public:
    void setUsername(string username);
    void setPassword(string password);
    void setEmail(string email);
    void setFirstname(string firstname);
    void setLastname(string lastname);
    void setGender(string gender);
    void setAge(int age);
    void setHeight(double height);
    void setWeight(double weight);
    void setBmi(double bmi);

    static bool validateUniqueUsername(const string &Username);
    static bool validateUsername(const string &Username);
    static bool validateUniqueEmail(const string &Email);
    static bool validateEmail(const string &Email);
    static bool validatePassword(const string &Password);
    static bool validateFirstname(const string &FirstName);
    static bool validateLastname(const string &LastName);
    static bool validateGender(const string &Gender);
    static bool validateAge(const int &Age);
    static bool validateHeight(const double &Height);
    static bool validateWeight(const double &Weight);

//    string getUsername();
//    string getPassword();
//    string getEmail();
//    string getFirstname();
//    string getLastname();
//    string getGender();

//    [[nodiscard]] signed int getAge() const;
//    double getHeight();
//    double getWeight();
    double getBmi() const;

    bool loginUser();
    void signupUser();
    void calcBmi();
    static double roundNumber(double number);
    ~ProfileData();
};


#endif //ENHANCEDUSERSYSTEM_PROFILEDATA_H
