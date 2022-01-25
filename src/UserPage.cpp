#include "UserPage.h"

UserPage::UserPage(string username) {
    Username = move(username);
    personalDetails();
}

void UserPage::userMenu() {
    cout << "\nWelcome " << Username << '!' << endl;
    cout << "[0] Exit" << endl;
    cout << "[1] Display Data" << endl;
    cout << "[2] Change Data\n" << endl;
    try {
        signed int choice;
        cout << "Selection:" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 0:
                break;
            case 1:
                displayData();
                break;
            case 2:
                changeData();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

void UserPage::changeData() {
    cout << "\n[Change Data]" << endl;
}

void UserPage::displayData() {
    cout << "\n[Profile Data]" << endl;
    cout << "Username: " << Username << endl;
    cout << "Password: " << Password << endl;
    cout << "Email: " << Email << endl;
}

void UserPage::personalDetails() {
    string username;
    Encryption crypt{};
    crypt.decrypt();
    ifstream userList("temp.csv");

    while (getline(userList, users)) {
        username = users.substr(0, users.find(','));
        if (Username == username) {
            users.erase(0, users.find(',') + 1);
            Password = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            Email = users.substr(0, users.find(','));
        }
    }
    userList.close();
    crypt.encrypt();
}

UserPage::~UserPage() = default;