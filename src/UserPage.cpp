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
    changeUsername();
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

void UserPage::changeUsername() {
    Encryption crypt{};
    string testRepl = "username";
    string newRepl = "newusername," + Password + ',' + Email;

    crypt.decrypt();
    fstream userFile("temp.csv", ios::in);
    if (userFile.is_open()) {
        string user;
        vector<string> users_details;
        while(getline(userFile, user)) {
            cout << user << endl;
            string::size_type pos = 0;
            while ((pos = user.find(testRepl, pos)) != string::npos) {
                user.replace(pos, user.size(), newRepl);
                pos += newRepl.size();
            }
            users_details.push_back(user);
        }
        userFile.close();
        userFile.open("newList.csv", ios::out | ios::trunc);
        for (const auto& i : users_details) {
            cout << i;
            userFile << i << endl;
        }
    }
    crypt.encrypt();
}

void UserPage::changePassword() {

}

void UserPage::changeEmail() {

}

UserPage::~UserPage() = default;