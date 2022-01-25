#include "UserPage.h"

using namespace std;

void showUsers() {
    string users;
    Encryption crypt{};

    crypt.decrypt();
    ifstream userList("temp.csv");
    while (getline(userList, users)) {
        cout << users << endl;
    }
    userList.close();
    crypt.encrypt();
}

int main() {
    string username;
    string password;
    string email;
    string firstname;
    string lastname;
    string gender;
    signed int age;
    double height;
    double weight;

    ProfileData User;

    signed int choice;
    while (true) {
        cout << "\n[ LOGIN SYSTEM ]\n" << endl;
        cout << "[0] Exit" << endl;
        cout << "[1] Login" << endl;
        cout << "[2] Sign Up" << endl;
        cout << "[3] Display Users\n" << endl;

        cout << "Selection: " << endl;
        try {
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 0:
                    return 0;

                case 1:
                    cout << "\n[ SING IN ]" << endl;
                    cout << "Enter username: " << endl;
                    cin >> username;
                    User.setUsername(username);
                    cout << "Enter password: " << endl;
                    cin >> password;
                    User.setPassword(password);
                    if (User.loginUser()) {
                        UserPage(username).userMenu();
                        return 0;
                    }
                    else {
                        cout << "Not logged in." << endl;
                    }
                    break;

                case 2:
                    cout << "\n[ SING UP ]" << endl;
                    while (true) {
                        try {
                            cout << "Enter Username:" << endl;
                            cin >> username;
                            if (!ProfileData::validateUniqueUsername(username)) {
                                cout << "Username is already in use.\n" << endl;
                                continue;
                            }
                            else if (!ProfileData::validateUsername(username)) {
                                cout << "Username must be at least 6 characters long.\n" << endl;
                                continue;
                            }
                            User.setUsername(username);

                            cout << "Enter Email:" << endl;
                            cin >> email;
                            if (!ProfileData::validateUniqueEmail(email)) {
                                cout << "Email already in use.\n" << endl;
                                continue;
                            }
                            if (!ProfileData::validateEmail(email)) {
                                cout << "Email is not a valid email.\n" << endl;
                                continue;
                            }
                            User.setEmail(email);
                            break;
                        }
                        catch (exception & e) {
                            cout << "Please enter a valid data type!" << endl;
                            cout << e.what() << endl;
                            continue;
                        }
                    }
                    while (true) {
                        try {
                            cout << "Enter Password:" << endl;
                            cin >> password;
                            if (!ProfileData::validatePassword(password)) {
                                cout << "Password must be at least 6 characters long.\n" << endl;
                                continue;
                            }
                            User.setPassword(password);

                            cout << "Enter Your First Name:" << endl;
                            cin >> firstname;
                            if (!ProfileData::validateFirstname(firstname)) {
                                cout << "First name can't contain digits.\n" << endl;
                                continue;
                            }
                            User.setFirstname(firstname);

                            cout << "Enter Your Last Name:" << endl;
                            cin >> lastname;
                            if (!ProfileData::validateLastname(lastname)) {
                                cout << "Last name can't contain digits.\n" << endl;
                                continue;
                            }
                            User.setLastname(lastname);

                            cout << "Enter Your Gender:" << endl;
                            cin >> gender;
                            if (!ProfileData::validateGender(gender)) {
                                cout << "Please only enter 'male' or 'female'.\n" << endl;
                                continue;
                            }
                            User.setGender(gender);
                            break;
                        }
                        catch (exception &e) {
                            cout << "Please enter a valid data type!" << endl;
                            cout << e.what() << endl;
                            continue;
                        }
                    }
                    while (true) {
                        try {
                            cout << "Enter Your Age:" << endl;
                            cin >> age;
                            if (!ProfileData::validateAge(age)) {
                                cout << "Please only enter a positive integer for your age..\n" << endl;
                                continue;
                            }
                            User.setAge(age);

                            cout << "Enter your height in meters:" << endl;
                            cin >> height;
                            if (!ProfileData::validateHeight(height)) {
                                cout << "Please enter a valid height in meters..\n" << endl;
                                continue;
                            }
                            User.setHeight(height);

                            cout << "Enter your weight in kilograms:" << endl;
                            cin >> weight;
                            if (!ProfileData::validateWeight(weight)) {
                                cout << "Please enter a valid weight in kilograms..\n" << endl;
                                continue;
                            }
                            User.setWeight(weight);
                            break;
                        }
                        catch (exception &e) {
                            cout << "Please enter a valid data type!" << endl;
                            cout << e.what() << endl;
                            continue;
                        }
                    }
                    User.calcBmi();
                    User.signupUser();
                    break;

                case 3:
                    showUsers();
                    break;

                default:
                    cout << "Choice out of scope.." << endl;
                    break;
            }
            continue;
        }
        catch (exception &e) {
            cout << e.what() << endl;
            cout << "You must enter an integer as displayed above.\n" << endl;
        }
    }
}
