#include <iostream>
#include <string>

using namespace std;

int cursor;

class Bank
{
public:
    void menu();
    void addAccount();
    void removeAccount();
    void withdraw();
    void deposit();

};

int main()
{
    Bank bk;

    cout << "\nWelcome to your To-Do List" << endl;
    bk.menu();

    return 0;
}

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
        cout << "Create Account: Work in progress, enter another number" << endl;
        menu();
    }
    else if(cursor == 2)
    {
        // View account balance
        cout << "View Account: Work in progress, enter another number" << endl;
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

void Bank::addAccount()
{

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