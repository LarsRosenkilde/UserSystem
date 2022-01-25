#include "UserPage.h"

UserPage::UserPage(string username) {
    Username = move(username);
    personalDetails();
}

void UserPage::userMenu() {
    cout << "\nWelcome " << FirstName << ' ' << LastName << '!' << endl;
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
    ProfileData User;
    cout << "\n[Change Data]" << endl;
    while (true) {
        try {
            cout << "Enter Your Age:" << endl;
            cin >> age;
            if (!ProfileData::validateAge(age)) {
                cout << "Please only enter an integer for your age..\n" << endl;
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

    newHeight = to_string(height);
    newHeight = newHeight.erase(newHeight.find_last_not_of('0') + 1, string::npos);

    newWeight = to_string(weight);
    newWeight = newWeight.erase(newWeight.find_last_not_of('0') + 1, string::npos);
    if (newWeight[newWeight.length() - 1] == '.') {
        newWeight.pop_back();
    }

    newBmi = to_string(User.getBmi());
    newBmi = newBmi.erase(newBmi.find_last_not_of('0') + 1, string::npos);

    newData = Username + ',' + Password + ',' + Email + ',' + FirstName + ',' + LastName + ',' + Gender + ',' +
            to_string(age) + ',' + newHeight + ',' + newWeight + ',' + newBmi;


    Encryption crypt{};
    crypt.decrypt();
    ifstream userList("temp.csv");
    vector<string> accounts;
    string input;
    string username;
    while (getline(userList, input)) {
        accounts.push_back(input);
        cout << input << endl;
    }
    for (auto& line: accounts) {
        username = users.substr(0, input.find(','));
        cout << username << endl;
        if (username == Username) {
            cout << "User found!" << endl;
        }
    }
    userList.close();
    crypt.encrypt();
//    string oldData;
//    string tempStr;
//    string username;
//    Encryption crypt{};
//    crypt.decrypt();
//    ifstream userList("temp.csv");
//    ofstream newUserList("test.csv");
//    while (getline(userList, users)) {
//        username = users.substr(0, users.find(','));
//        if (Username == username) {
//            oldData = users;
//        }
//    }
//    while (userList >> tempStr) {
//        cout << tempStr;
//        if (tempStr == oldData) {
//            tempStr = newData;
//            cout << "if activated" << endl;
//        }
//        tempStr += '\n';
//        newUserList << tempStr;
//    }
//    userList.close();
//    newUserList.close();
//    crypt.encrypt();
//    cout << "\nNew data added successfully." << endl;
}

void UserPage::displayData() {
    cout << "\n[Profile Data]" << endl;
    cout << "Username: " << Username << endl;
    cout << "Email: " << Email << endl;
    cout << "Name: " << FirstName << ' ' << LastName << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Age: " << Age << endl;
    if (Height == Age) {
        cout << "Height: " << "N/A" << endl;
        cout << "Weight: " << "N/A" << endl;
        cout << "Bmi: " << "N/A" << endl;
    }
    else {
        cout << "Height: " << Height << endl;
        cout << "Weight: " << Weight << endl;
        cout << "Bmi: " << Bmi << endl;
    }
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
            users.erase(0, users.find(',') + 1);
            FirstName = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            LastName = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            Gender = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            Age = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            Height = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            Weight = users.substr(0, users.find(','));
            users.erase(0, users.find(',') + 1);
            Bmi = users.substr(0, users.find(','));
        }
    }
    userList.close();
    crypt.encrypt();
}

UserPage::~UserPage() = default;