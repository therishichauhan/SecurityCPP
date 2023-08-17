#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int a,age,dob;
    string password1, password0, password2, pass, name, user, word, word1, old, text;
    string creds[2];

    cout << " Security system  " << endl;
    cout << "                                      " << endl;
    cout << endl;
    cout << endl;

    cout << "        1. Register             " << endl;
    cout << "        2. Log In               " << endl;
    cout << "        3. Change Password      " << endl;
    cout << "        4. End Program          " << endl;

    do {
        cout << endl << endl;

        cout << "Enter your choice" << endl;
        cin >> a;

        switch (a) {
            case 1: {
                cout << "-------REGISTER--------" << endl;
                cout << "Please Enter your credentials" << endl;
                cout << "Enter your username or email" << endl;
                cin >> name;
                cout << "Enter your Password";
                cin >> password0;
                cout << "Enter your age" << endl;
                cin >> age;
                cout << "Enter your D.O.B" << endl;
                cin >> dob;

                ofstream of1("file.txt", ios::app);
                if (of1.is_open()) {
                    of1 << name << " " << password0 << " " << age << " " << dob << endl;
                    cout << "Registration Successful" << endl;
                    of1.close();
                } else {
                    cout << "Failed to open file for writing." << endl;
                }
            }
            break;

            case 2: {
                cout << "------------Login-----------" << endl;
                cout << "Enter your username or email " << endl;
                cin >> user;
                cout << "Enter your Password";
                cin >> pass;

                ifstream of2("file.txt");
                bool loginSuccess = false;

                while (of2 >> name >> password1 >> age >> dob) {
                    if (user == name && pass == password1) {
                        cout << "------LogIn successful------" << endl;
                        loginSuccess = true;
                        break;
                    }
                }

                if (!loginSuccess) {
                    cout << "Incorrect Credentials" << endl;
                }

                of2.close();
            }
            break;

            case 3: {
                cout << "------------Change Password-----------" << endl;
                cout << "Enter your username or email " << endl;
                cin >> user;
                cout << "Enter your old password " << endl;
                cin >> old;
                cout << "Enter your new password: " << endl;
                cin >> password1;
                cout << "Re-enter your new password: " << endl;
                cin >> password2;

                ifstream of2("file.txt");
                ofstream temp("temp.txt");

                bool passwordChanged = false;

                while (of2 >> name >> password0 >> age >> dob) {
                    if (user == name && old == password0) {
                        if (password1 == password2) {
                            temp << name << " " << password1 << " " << age << " " << dob << endl;
                            passwordChanged = true;
                        } else {
                            cout << "Passwords do not match" << endl;
                            temp << name << " " << password0 << " " << age << " " << dob << endl;
                        }
                    } else {
                        temp << name << " " << password0 << " " << age << " " << dob << endl;
                    }
                }

                of2.close();
                temp.close();

                if (passwordChanged) {
                    remove("file.txt");
                    rename("temp.txt", "file.txt");
                    cout << "Password changed successfully" << endl;
                } else {
                    remove("temp.txt");
                    cout << "Incorrect credentials or old password" << endl;
                }
            }
            break;

            case 4: {
                cout << "-------------Thank you---------" << endl;
                return 0; // End the program
            }
            break;

            default: {
                cout << "Enter a valid choice" << endl;
            }
        }
    } while (a != 4);

    return 0;
}
