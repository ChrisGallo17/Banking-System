#include <iostream>
#include <string>

using namespace std;

int cursor, i, j, acNum[100], acPin[100], acBalance[100];
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

};

int main()
{
    Bank bk;

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
    cout << "Enter 5 to exit " << endl;

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

        cout << "Withdraw/Deposit: Work in progress, enter another number" << endl;
        menu();
    }
    else if(cursor == 4)
    {
        // Remove account function
        removeAccount();
        cout << "Remove account: Work in progress, enter another number" << endl;
        menu();
    }
    else if(cursor == 5)
    {
        exit(5);
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
    accountNum = accountNum - 1;

    if ( acNum[accountNum] == 0)
    {
        acNum[accountNum] = accountNum + 1;

        cout <<  acNum[accountNum] << " Enter a pin number: " << endl;
        cin >> pin;
        acPin[accountNum] = pin;
        cout << "Enter your Name" << endl;
        cin >> name;
        acName[accountNum] = name;
        cout << "How much money would you like to put into your account? " << endl;
        cin >> withdraw;
        acBalance[accountNum] = withdraw;
        cout << acName[accountNum] << ", your account has been created successfully!" << endl;
        cout << "Your current balance is $" << acBalance[accountNum] << endl;

        //cout << acName[accountNum] << acNum[accountNum] << acPin[accountNum] << endl;
    }
    else
    {
        cout << "This account number is already taken, please select another number: \n";
        addAccount();
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

    if (acNum[num] == 0) {
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

}

void Bank::withdraw()
{

}

void Bank::deposit()
{

}