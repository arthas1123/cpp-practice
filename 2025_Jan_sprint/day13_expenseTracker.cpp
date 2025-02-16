#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class ExpenseTracker
{
public:
    void addExpense()
    {
        string date, category, item;
        int amount;
        double price;

        cout << "Enter date (dd/mm/yyyy): ";
        cin >> date;
        cout << "Enter category (Food, Clothing, Entertainment, Housing, Medical, Transportation, Education, etc.): ";
        cin >> category;
        cout << "Enter item: ";
        cin >> item;
        cout << "Enter amount: ";
        cin >> amount;
        cout << "Enter price: ";
        cin >> price;

        double total = amount * price;
        cout << "Total price: " << total << endl;

        ofstream file("expenses.txt", ios::app);
        if (file.is_open())
        {
            file << date << " " << category << " " << item << " " << amount << " " << price << " " << total << endl;
            file.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }

    void viewExpenses()
    {
        ifstream file("expenses.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }

    void deleteExpense()
    {
        string date;
        cout << "Enter date to delete: ";
        cin >> date;

        ifstream file("expenses.txt");
        ofstream temp("temp.txt");
        if (file.is_open() && temp.is_open())
        {
            string line;
            while (getline(file, line))
            {
                if (line.substr(0, 10) != date)
                {
                    temp << line << endl;
                }
            }
            file.close();
            temp.close();
            remove("expenses.txt");
            rename("temp.txt", "expenses.txt");
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }

    void createNewFile()
    {
        ofstream file("expenses.txt");
        if (file.is_open())
        {
            file << "Date Category Item Amount Price Total" << endl;
            file.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }

    void loadFromFile()
    {
        ifstream file("expenses.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }

    void displayMenu()
    {
        cout << "Expense Tracker" << endl;
        cout << "1. Add expense" << endl;
        cout << "2. View expenses" << endl;
        cout << "3. Delete expense" << endl;
        cout << "4. Create new file" << endl;
        cout << "5. Load from file" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
    }
};

int main()
{
    ExpenseTracker tracker;
    int choice;
    do
    {
        tracker.displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            tracker.addExpense();
            break;
        case 2:
            tracker.viewExpenses();
            break;
        case 3:
            tracker.deleteExpense();
            break;
        case 4:
            tracker.createNewFile();
            break;
        case 5:
            tracker.loadFromFile();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}
