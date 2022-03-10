#include <iostream>
#include <string>
#define MIN_BALANCE 500

class Account;

class Bank
{
    int n, last_acc = 0;
    Account **accounts;

public:
    Bank()
    {
        n = 0;
        accounts = NULL;
    }
    void open_acc();
    void close_acc();
    double withdraw();
    double deposit();
    Account *get_acc();
};

class Account
{
    std::string cust_name, acc_type;
    int acc_no;
    double balance;

public:
    Account(std::string name, std::string type, int no, double bal)
    {
        cust_name = name;
        acc_type = type;
        acc_no = no;
        balance = bal;
    }
    double withdraw(double amount);
    double deposit(double amount)
    {
        balance += amount;
        std::cout << "Deposit successful!\n\n";
        return balance;
    }
    double balance_enquiry()
    {
        std::cout << "Balance: " << balance << "\n\n";
        return balance;
    }
    void acc_statement();
    int get_acc_no() { return acc_no; }
};

double Account::withdraw(double amount)
{
    if (amount > balance)
    {
        std::cout << "Not enough balance!" << '\n'
                  << "Balance: " << balance << "\n\n";
    }
    else if (balance - amount < MIN_BALANCE)
    {
        std::cout << "Balance cannot be less than " << MIN_BALANCE << '\n';
	return 0;
    }
    else
    {
        balance -= amount;
        std::cout << "Withdrawal successful!\n\n";
    }
    return balance;
}

void Account::acc_statement()
{
    std::cout << "Customer name: " << cust_name << '\n'
              << "Account number: " << acc_no << '\n'
              << "Account type: " << acc_type << '\n'
              << "Balance: " << balance << "\n\n";
}

Account *Bank::get_acc()
{
    Account *acc = NULL;
    std::string num_str;
    int num;

    std::cout << "Enter acc no: ";
    std::cin >> num_str;
    num = stoi(num_str);

    for (int i = 0; i < n; i++)
    {
        if (accounts[i]->get_acc_no() == num)
        {
            acc = accounts[i];
            break;
        }
    }
    std::cout << "\n";
    return acc;
}

void Bank::open_acc()
{
    std::string name, type, bal_str;
    double bal;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter type of account: ";
    std::cin >> type;
    do
    {
        std::cout << "Initial deposit (" << MIN_BALANCE << " is minimum): ";
        std::cin >> bal_str;
        bal = std::stod(bal_str);
    } while (bal < MIN_BALANCE);
    n++;
	last_acc++;
    Account *acc = new Account(name, type, last_acc, bal);
    Account **new_list = new Account *[n];
    for (int i = 0; i < n - 1; i++)
    {
        new_list[i] = accounts[i];
		delete accounts[i];
    }
    new_list[n - 1] = acc;
    delete[] accounts;
    accounts = new_list;

    std::cout << "Your account number is: " << last_acc << "\n\n";
}

void Bank::close_acc()
{
    Account *acc = NULL;
    std::string num_str;
    int num, rm = 0;

    std::cout << "Enter acc no: ";
    std::cin >> num_str;
    num = std::stoi(num_str);

    n--;
    Account **new_list = new Account *[n];

    for (int i = 0; i < n + 1; i++)
    {
        if (accounts[i]->get_acc_no() == num)
        {
            acc = accounts[i];
            rm = 1;
        }
        else
        {
            new_list[i - rm] = accounts[i];
        }
    }
    if (!acc)
    {
        std::cout << "No such account exists.\n\n";
        return;
    }

    delete[] accounts;
    delete acc;
    accounts = new_list;

    std::cout << "Account closed successfully.\n\n";
}

double Bank::withdraw()
{
    std::string amount_str;
    double amount;
    Account *acc = get_acc();
    if (!acc)
    {
        std::cout << "No such account exists.\n\n";
        return 0;
    }

    std::cout << "Enter amount: ";
    std::cin >> amount_str;
    amount = std::stod(amount_str);
    return acc->withdraw(amount);
}

double Bank::deposit()
{
    std::string amount_str;
    double amount;
    Account *acc = get_acc();
    if (!acc)
    {
        std::cout << "No such account exists.\n\n";
        return 0;
    }

    std::cout << "Enter amount: ";
    std::cin >> amount_str;
    amount = std::stod(amount_str);

    return acc->deposit(amount);
}

void print_header(std::string header)
{
    std::string line = "***********************\n";
    std::cout << "\n"
              << line << header << "\n"
              << line;
}

int main()
{
    std::string choice_str;
    int choice = 0;
    Bank bank;
    Account *acc;

	print_header("BANK");

    do
    {
        std::cout << "1. Open New Account\n2. Withdrawal\n3. Deposit\n4. Balance Enquiry\n5. Account Statement\n6. Close Account\n7. Exit\n";
        std::cout << ">>> ";
        std::cin >> choice_str;
        choice = std::stoi(choice_str);

        switch (choice)
        {
        case 1:
            print_header("Open New Account");
            bank.open_acc();
            break;
        case 2:
            print_header("Withdrawal");
            bank.withdraw();
            break;
        case 3:
            print_header("Deposit");
            bank.deposit();
            break;
        case 4:
			acc = bank.get_acc();
            print_header("Balance enquiry");
            if (!acc)
            {
                std::cout << "No such account exists.\n\n";
                continue;
            }
            acc->balance_enquiry();
            break;
        case 5:
            acc = bank.get_acc();
			print_header("Account Statement");
            if (!acc)
            {
                std::cout << "No such account exists.\n\n";
                continue;
            }
            acc->acc_statement();
            break;
        case 6:
            print_header("Close Account");
            bank.close_acc();
        case 7:
            break;
        default:
            std::cout << "Invalid choice. Please try again...\n\n";
        }
    } while (choice != 7);
}
