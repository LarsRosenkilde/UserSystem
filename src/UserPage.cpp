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
    string newUsername;
    string newPass;
    string newMail;
    cout << "\n[Change Data]" << endl;
    cout << "[1] Username" << endl;
    cout << "[2] Password" << endl;
    cout << "[3] Email\n" << endl;
    try {
        signed int choice;
        cout << "Selection: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                while (true) {
                    cout << "\n[Change Username]" << endl;
                    cout << "Enter new username: ";
                    cin >> newUsername;
                    cin.ignore();
                    if (!ProfileData::validateUniqueUsername(newUsername)) {
                        cout << "Username is already in use.\n" << endl;
                        continue;
                    }
                    else if (!ProfileData::validateUsername(newUsername)) {
                        cout << "Username must be at least 6 characters long.\n" << endl;
                        continue;
                    }
                    changeUsername(newUsername);
                    break;
                }
                break;
            case 2:
                cout << "\n[Change Password]" << endl;
                cout << "Enter new password: ";
                cin >> newPass;
                cin.ignore();
            case 3:
                cout << "\n[Change Email]" << endl;
                cout << "Enter new email: ";
                cin >> newPass;
                cin.ignore();
            default:
                cout << "Invalid choice.." << endl;
                break;
        }
    }
    catch (exception& e) {
        cout << e.what();
    }
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

void UserPage::changeUsername(const string& newUsername) {
    Encryption crypt{};
    string newRepl = newUsername + ',' + Password + ',' + Email;

    crypt.decrypt();
    fstream userFile("temp.csv", ios::in);
    if (userFile.is_open()) {
        string user;
        vector<string> users_details;
        while(getline(userFile, user)) {
            string::size_type pos = 0;
            while ((pos = user.find(Username, pos)) != string::npos) {
                user.replace(pos, user.size(), newRepl);
                pos += newRepl.size();
            }
            users_details.push_back(user);
        }
        userFile.close();
        userFile.open("newList.csv", ios::out | ios::trunc);
        for (const auto& i : users_details) {
            userFile << i << endl;
        }
    }
    userFile.close();
    try {
        if (filesystem::remove("temp.csv")) {
            rename("newList.csv", "temp.csv");
            cout << "Username changed successfully to " + newUsername << endl;
        }
        else {
            cout << "Username couldn't be changed at this moment." << endl;
        }
    }
    catch (const filesystem::filesystem_error& e) {
        cout << e.what() << endl;
    }
    crypt.encrypt();
}

void UserPage::changePassword() {

}

void UserPage::changeEmail() {

}

UserPage::~UserPage() = default;