#include <iostream>
#include <string>

using namespace std;

int cursor, acNum[100], acPin[100], acBalance[100];
string acName[100];

class Bank
{
public:
    void menu();
    void addAccount();
    void viewAccount();
    void removeAccount();
    void withdraw();
    void deposit();
    void checkAccounts();

};

int main()
{
    Bank bk;

    acNum[72] = 72;
    acPin[72] = 72;
    acBalance[72] = 500;
    acName[72] = "Yoda";

    acNum[34] = 34;
    acPin[34] = 34;
    acBalance[34] = 700;
    acName[34] = "Chewy";

    acNum[55] = 55;
    acPin[55] = 55;
    acBalance[55] = 1000;
    acName[55] = "Obi'Wan";

    cout << "\nWelcome to your Banking System" << endl;
    bk.menu();

    return 0;
}

// This function gives the user a menu interface
void Bank::menu()
{
    cout << "\nEnter 1 to create an account " << endl;
    cout << "Enter 2 to view account balance " << endl;
    cout << "Enter 3 to withdraw or deposit from account " << endl;
    cout << "Enter 4 to remove account " << endl;
    cout << "Enter 5 to view accounts (admin) " << endl;
    cout << "Enter 6 to exit " << endl;

    cursor = 0;

    cin >> cursor;

    if (cursor == 1)
    {
        // Create account function
        addAccount();
        menu();
    }
    else if(cursor == 2)
    {
        // View account balance
        viewAccount();
        menu();
    }
    else if(cursor == 3)
    {
        // Withdraw or deposit function
        char input;

        cout << "Would you like to withdraw or deposit from your account?" << endl;
        cout << "w for withdraw / d for deposit:" << endl;
        cin >> input;

        if (input == 'w') {
            withdraw();
        }
        else if (input == 'd') {
            deposit();
        }
        else{
            cout << "Invalid input:" << endl;
        }

        menu();

    }
    else if(cursor == 4)
    {
        // Remove account function
        removeAccount();
        menu();
    }
    else if(cursor == 5)
    {
        checkAccounts();
        menu();
    }
    else if(cursor == 6)
    {
        exit(6);
    }
    else
    {
        cout << "Please enter a valid option" << endl;
        menu();
    }
}

// Creates an account for the user
void Bank::addAccount()
{
    int accountNum, pin, withdraw;
    string name;

    cout << "Input your desired bank account number, from 1-100: " << endl;
    cin >> accountNum;
    accountNum = accountNum - 1; // Subtracted 1 because the array is from 0-99

    if (accountNum < 0 || accountNum > 99){ // Checks to make sure it input is within bounds of array
        cout << "Enter a number between 1 and 100" << endl;
        addAccount();
    }
    else {
        if (acNum[accountNum] == 0) {
            acNum[accountNum] = accountNum + 1;

            cout << "Enter a pin number: " << endl;
            cin >> pin;
            acPin[accountNum] = pin;
            cout << "Enter your first name" << endl;
            cin >> name;
            acName[accountNum] = name;
            cout << "How much money would you like to put into your account? " << endl;
            cin >> withdraw;

            if (withdraw < 0){
                cout << acName[accountNum] << ", you cannot start you account in debt." << endl;
                cout << "Your account will be created with a balance of $0" << endl;
                acBalance[accountNum] = 0;
            }
            else {
                acBalance[accountNum] = withdraw;
                cout << acName[accountNum] << ", your account has been created successfully!" << endl;
                cout << "Your current balance is $" << acBalance[accountNum] << endl;
            }

        } else {
            cout << "This account number is already taken, please select another number: \n";
            addAccount();
        }
    }

    accountNum = 0;
    pin = 0;
    withdraw = 0;

}

void Bank::viewAccount() {
    int num, pin;

    cout << "Enter your account number: " << endl;
    cin >> num;
    num = num - 1;

    //Checks for valid account
    if (num < 0 || num >= 100) {
        cout << "Enter a number between 1 and 100." << endl;
        viewAccount();
    }
    else if (acNum[num] == 0) {
        cout << "This account does not exist." << endl;
        viewAccount();
    }
    else {
        cout << "Welcome " << acName[num] << ", your account number is " << acNum[num];
        cout << ".\nEnter your pin to check your balance: " << endl;
        cin >> pin;

        if (pin == acPin[num]) {
            cout << "Your current balance is $" << acBalance[num] << endl;
        }
        else {
            cout << "Incorrect pin number for account number " << acNum[num] << endl;
            cout << "Try another account." << endl;
            viewAccount();
        }
    }
}

void Bank::removeAccount()
{
    int num, pin;
    string confirm;

    cout << "Enter your account number: " << endl;
    cout << "Enter 0 to go back to the menu:" << endl;
    cin >> num;
    num = num - 1;

    if (num <= -2 || num >= 100) {
        cout << "Please enter a valid number" << endl;
        removeAccount();
    }
    else if(num == (-1)){
        // Takes user back to the menu if they enter 101
    }
    else if (acNum[num] == 0) {
        cout << "This account does not exist." << endl;
        removeAccount();
    }
    else {
        cout << "Welcome " << acName[num] << ", your account number is " << acNum[num];
        cout << ".\nEnter your pin to remove your account: " << endl;
        cin >> pin;
        //Checks if pin is correct, then proceeds with the withdraw
        if (pin == acPin[num]) {
            cout << acName[num] << ", are you sure you would like to erase your account?" << endl;
            cout << "Enter y for yes / n for no:" << endl;
            cin >> confirm;

            if (confirm == "y") {
                acName[num] = "";
                acNum[num] = 0;
                acBalance[num] = 0;
                acPin[num] = 0;

                cout << "Your account has been removed from the system" << endl;
            }
            else if (confirm == "n") {
                cout << "Your account was not removed" << endl;
            }
            else {
                cout << "The input was not valid and the account was not removed" << endl;
            }
        }
        else {
            cout << "Incorrect pin number for account number " << acNum[num] << endl;
            cout << "Try another account." << endl;
            removeAccount();
        }
    }

}

void Bank::withdraw()
{
    int wd, num, pin;

    cout << "Enter your account number: " << endl;
    cin >> num;
    num = num - 1;

    //Checks if account exists
    if (acNum[num] == 0) {
        cout << "This account does not exist." << endl;
        withdraw();
    }
    else {
        cout << "Welcome " << acName[num] << ", your account number is " << acNum[num];
        cout << ".\nEnter your pin to withdraw from your account: " << endl;
        cin >> pin;

        //Checks if pin is correct, then proceeds with the withdraw
        if (pin == acPin[num]) {
            cout << "Your current balance is $" << acBalance[num] << endl;
            cout << "How much money would you like to withdraw?" << endl;
            cin >> wd;

            if (acBalance[num] < wd){
                cout << "You do not have enough money in your account" << endl;
                cout << "Please try again." << endl;
                withdraw();
            }
            else {
                acBalance[num] = acBalance[num] - wd;
                cout << "Your balance is now $" << acBalance[num];
            }
        }
        else {
            cout << "Incorrect pin number for account number " << acNum[num] << endl;
            cout << "Try another account." << endl;
            withdraw();
        }
    }

}

void Bank::deposit()
{
    int dp, num, pin;

    cout << "Enter your account number: " << endl;
    cin >> num;
    num = num - 1;

    //Checks if Account exists
    if (acNum[num] == 0) {
        cout << "This account does not exist." << endl;
        deposit();
    }
    else {
        cout << "Welcome " << acName[num] << ", your account number is " << acNum[num];
        cout << ".\nEnter your pin to withdraw from your account: " << endl;
        cin >> pin;

        //Checks if pin is correct, then proceeds with the deposit
        if (pin == acPin[num]) {
            cout << "Your current balance is $" << acBalance[num] << endl;
            cout << "How much money would you like to deposit?" << endl;
            cin >> dp;

            acBalance[num] = acBalance[num] + dp;

            cout << "Your balance is now $" << acBalance[num];
        }
        else {
            cout << "Incorrect pin number for account number " << acNum[num] << endl;
            cout << "Try another account." << endl;
            deposit();
        }
    }
}

// Administrative function to see all current accounts
// Master Pin is 4321
void Bank::checkAccounts() {

    int pin, i;

    cout << "Enter master pin to view all accounts: " << endl;
    cin >> pin;

    if (pin == 4321) {
        cout << "Account number, name, and balance: " << endl;

        for (i = 0; i < 100; i++){
            if (acNum[i] != 0){
                cout << acNum[i] << " " << acName[i] << " $" << acBalance[i] << endl;
            }
        }
    }
    else {
        cout << "Incorrect master pin " << endl;
    }
}
