#include "ProfileData.h"

Encryption crypt{};

void ProfileData::setUsername(string username) {
    Username = move(username);
}

void ProfileData::setPassword(string password) {
    Password = move(password);
}

void ProfileData::setEmail(string email) {
    Email = move(email);
}

void ProfileData::setFirstname(string firstname) {
    if (firstname[0] > 96 && firstname[0] < 126) {
        firstname[0] = char(firstname[0] - 32);
    }
    Firstname = move(firstname);
}

void ProfileData::setLastname(string lastname) {
    if (lastname[0] > 96 && lastname[0] < 126) {
        lastname[0] = char(lastname[0] - 32);
    }
    Lastname = move(lastname);
}

void ProfileData::setGender(string gender) {
    Gender = move(gender);
}

void ProfileData::setAge(signed int age) {
    Age = age;
}

void ProfileData::setHeight(double height) {
    Height = height;
}

void ProfileData::setWeight(double weight) {
    Weight = weight;
}

void ProfileData::setBmi(double bmi) {
    Bmi = bmi;
}

//string ProfileData::getUsername() {
//    return Username;
//}
//
//string ProfileData::getPassword() {
//    return Password;
//}
//
//string ProfileData::getEmail() {
//    return Email;
//}
//
//string ProfileData::getFirstname() {
//    return Firstname;
//}
//
//string ProfileData::getLastname() {
//    return Lastname;
//}
//
//string ProfileData::getGender() {
//    return Gender;
//}
//
//int ProfileData::getAge() const {
//    return Age;
//}
//
//double ProfileData::getHeight() {
//    return Height;
//}
//
//double ProfileData::getWeight() {
//    return Weight;
//}

double ProfileData::getBmi() const {
    return Bmi;
}

bool ProfileData::validateUniqueUsername(const string& Username) {
    string users;
    string username;

    crypt.decrypt();
    ifstream userList("temp.csv");
    while (getline(userList, users)) {
        if (Username == users.substr(0, users.find(','))) {
            userList.close();
            crypt.encrypt();
            return false;
        }
    }
    userList.close();
    crypt.encrypt();
    return true;
}

bool ProfileData::validateUsername(const string& Username) {
    if (Username.length() >= 6) {
        return true;
    }
    return false;
}

bool ProfileData::validateUniqueEmail(const string &Email) {
    string users;
    string email;

    crypt.decrypt();
    ifstream userList("temp.csv");
    while (getline(userList, users)) {
        users.erase(0, users.find(',') + 1);
        users.erase(0, users.find(',') + 1);
        if (Email == users.substr(0, users.find(','))) {
            userList.close();
            crypt.encrypt();
            return false;
        }
    }
    userList.close();
    crypt.encrypt();
    return true;
}

bool ProfileData::validateEmail(const string& Email) {
    string regx = R"(^[^@\s]+@[^@\s]+\.[^@\s]+$)";
    if (regex_match(Email, regex(regx))) {
        return true;
    }
    return false;
}

bool ProfileData::validatePassword(const string& Password) {
    if (Password.length() >= 6) {
        return true;
    }
    return false;
}

bool ProfileData::validateFirstname(const string& FirstName) {
    if (!regex_match(FirstName, regex(".*[0-9].*"))) {
        return true;
    }
    return false;
}

bool ProfileData::validateLastname(const string& LastName) {
    if (!regex_match(LastName, regex(".*[0-9].*"))) {
        return true;
    }
    return false;
}

bool ProfileData::validateGender(const string& Gender) {
    if (Gender == "male" || Gender == "female") {
        return true;
    }
    return false;
}

bool ProfileData::validateAge(const int& Age) {
    if (Age > 0 && Age < 150) {
        return true;
    }
    return false;
}

bool ProfileData::validateHeight(const double& Height) {
    if (Height > 0 && Height < 3) {
        return true;
    }
    return false;
}

bool ProfileData::validateWeight(const double& Weight) {
    if (Weight > 0 && Weight < 300) {
        return true;
    }
    return false;
}

bool ProfileData::loginUser() {
    string users;
    string username;
    string password;

    crypt.decrypt();
    ifstream userList("temp.csv");

    while (getline(userList, users)) {
        username = users.substr(0, users.find(','));
        if (Username == username) {
            users.erase(0, users.find(',') + 1);
            password = users.substr(0, users.find(','));
            if (Password == password) {
                userList.close();
                crypt.encrypt();
                return true;
            }
        }
    }
    userList.close();
    crypt.encrypt();
    return false;
}

void ProfileData::signupUser() {
    ofstream usersList;
    crypt.decrypt();
    usersList.open("temp.csv", ios_base::app);
    usersList << Username << ',';
    usersList << Password << ',';
    usersList << Email << ',';
    usersList << Firstname << ',';
    usersList << Lastname << ',';
    usersList << Gender << ',';
    usersList << Age << ',';
    usersList << Height << ',';
    usersList << Weight << ',';
    usersList << Bmi << "\n";

    usersList.close();
    cout << "User saved successfully!\n" << endl;
    crypt.encrypt();
}

double ProfileData::roundNumber(double number) {
    double round_off = pow(10.0f, 2.0);
    return round(number * round_off) / round_off;
}

void ProfileData::calcBmi() {
    double NewBmi = Weight / (pow(Height, 2));
    setBmi(roundNumber(NewBmi));
}

ProfileData::~ProfileData() = default;
