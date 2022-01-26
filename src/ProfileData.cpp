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
    usersList << Email << '\n';

    usersList.close();
    cout << "User saved successfully!\n" << endl;
    crypt.encrypt();
}

void ProfileData::changeUsername() {
    string testRepl = "username";
    string newRepl = "newusername";

    crypt.decrypt();
    fstream userFile("temp.csv", ios::in);
    if (userFile.is_open()) {
        string user;
        vector<string> users;
        while(getline(userFile, user)) {
            cout << user << endl;
            string::size_type pos = 0;
            while ((pos = user.find(testRepl, pos)) != string::npos) {
                user.replace(pos, user.size(), newRepl);
                pos += newRepl.size();
            }
            users.push_back(user);
        }
        userFile.close();
        userFile.open("newList.csv", ios::out | ios::trunc);
        for (const auto& i : users) {
            userFile << i << endl;
        }
    }
    crypt.encrypt();
}

void ProfileData::changePassword() {

}

void ProfileData::changeEmail() {

}

ProfileData::~ProfileData() = default;
