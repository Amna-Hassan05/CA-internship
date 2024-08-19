#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>
#include <string>
using namespace std;

// Function to display menu
void menu() {
    cout << "\n\nDo you want to\n"
         << "\033[32m1. Register\n2. Login\n3. Leave\033[0m\n";
}

// Function to generate a strong password
string strong_pass(int len) {
    string strong_pass;
    string alpha_box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";

    // Seed random number
    srand(time(0));

    for (int p = 0; p < len; p++) {
        strong_pass += alpha_box[rand() % alpha_box.length()];
    }

    return strong_pass;
}

// Function to hash password (simple approach)
string hash_password(const string& pass) {
    string hashed = pass;
    for (size_t i = 0; i < hashed.length(); ++i) {
        hashed[i] += 3; // Simple Caesar Cipher-like hash (rotate characters)
    }
    return hashed;
}


// Function to check if username already exists
bool username_exists(const string& username) {
    ifstream file("credentials.txt");
    string file_UN, file_PASS;

    while (getline(file, file_UN)) {
        getline(file, file_PASS);
        if (file_UN == username) {
            return true;
        }
    }

    return false;
}

// Function to handle registration process
void registration() {
    string un, pass;
    int sugg;

    cout << "\nFor Registration please enter\n"
         << "Username: ";
    cin.ignore();
    getline(cin, un);

    if (username_exists(un)) {
        cout << "\nUsername already exists. Please choose another username.\n";
        return;
    }

    cout << "Press 1 if you want a suggestion for a strong password and 0 otherwise: ";
    cin >> sugg;

    if (sugg == 1) {
        pass = strong_pass(8); // Parameter requires 8-character password suggestion
        cout << "\nSuggested Password: " << pass << endl;
    } else {
        cout << "\nPassword: ";
        cin.ignore();
        getline(cin, pass);
    }

    // Save credentials in a file
    ofstream file("credentials.txt", ios::app);

    if (!file) {
        cout << "\nERROR! File has not been opened...\n";
    } else {
        file << un << endl;
        file << hash_password(pass) << endl; // Save hashed password
        file.close();
    }

    cout << "\nYou are successfully registered!\n";
}

// Function to handle login process
void login() {
    string UN, PASS, file_UN, file_PASS;
    bool logged_in = false;  // Initially false

    cout << "\nFor login enter\nYour username: ";
    cin.ignore();
    getline(cin, UN);

    cout << "\nPassword: ";
    getline(cin, PASS);

    ifstream f("credentials.txt");

    if (!f) {
        cout << "\nERROR! File has not been opened...\n";
    } else {
        while (getline(f, file_UN)) {
            getline(f, file_PASS);
            if ((file_UN == UN) && (file_PASS == hash_password(PASS))) { // Compare hashed passwords
                logged_in = true;
                break;
            }
        }
        f.close();
    }

    if (logged_in) {
        cout << "\n***  You have been successfully logged in! ***\n";
    } else {
        cout << "\n***  Incorrect username or password! ***\n";
    }
}

// Function to exit the system
void leave() {
    cout << "\nExiting from system ... \n";
    exit(0);
}

int main() {
    int option;

    cout << "\n\033[35m  _______________________________________________________\n\n"
         << " |\t\t\tWELCOME TO\t\t\t|\n"
         << " |\t\tLOGIN AND REGISTRATION SYSTEM\t\t|\n"
         << "\n  _______________________________________________________\033[0m";

    do {
        // Calling menu function    
        menu();
        cin >> option;

        // Option chosen from the menu
        switch (option) {
            case 1:
                registration();
                break;

            case 2:
                login();
                break;

            case 3:
                leave();
                break;

            default:
                cout << "\n\n......  Invalid Option!  ......\n";
        }

    } while (option != 3);

    return 0;
}
