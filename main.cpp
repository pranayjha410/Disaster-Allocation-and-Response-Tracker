#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Disaster
{
    string id;
    string type;
    string location;
    int severity;
    int affectedPeople;

public:
    string getId()
    {
        return id;
    }
    Disaster(string id, string type, string location,
             int severity, int affectedPeople)
    {
        this->id = id;
        this->type = type;
        this->location = location;
        this->severity = severity;
        this->affectedPeople = affectedPeople;
    }

    void display()
    {
        cout << "Disaster ID: " << id << endl;
        cout << "Type: " << type << endl;
        cout << "Location: " << location << endl;
        cout << "Severity: " << severity << endl;
        cout << "Affected People: " << affectedPeople << endl;
    }
};
int main()
{
    vector<Disaster> disasters;
    int choice;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Disaster\n";
        cout << "2. View Disasters\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string id;
            string type;
            string location;
            int severity;
            int affectedPeople;

            bool exists;

            do
            {
                exists = false;

                cout << "Enter Disaster ID: ";
                cin >> id;

                for (int i = 0; i < disasters.size(); i++)
                {
                    if (disasters[i].getId() == id)
                    {
                        cout << "Disaster ID already exists.\n";
                        cout << "Please enter a different ID.\n";

                        exists = true;
                        break;
                    }
                }

            } while (exists);

            cin.ignore();
            cout << "Enter Type (e.g. Flood): ";
            getline(cin, type);
            cout << "Enter Location: ";
            getline(cin, location);
            cout << "Enter Severity (1-10): ";
            cin >> severity;
            while (cin.fail() || severity < 1 || severity > 10)
            {
                if (cin.fail())
                {
                    // 1. Reset the error flag
                    cin.clear();
                    // 2. Clear the invalid text (like "abc") out of the buffer
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter only numbers: ";
                }
                else
                {
                    // The input was a number, but out of the 1-10 range
                    cout << "Invalid severity. Please enter a value between 1 and 10: ";
                }

                // Try reading the input again
                cin >> severity;
            }
            cout << "Enter Affected People: ";
            cin >> affectedPeople;
            while (affectedPeople <= 0)
            {
                cout << "Invalid number. Please enter a positive value: ";
                cin >> affectedPeople;
            }

            disasters.push_back(Disaster(id, type, location, severity, affectedPeople));
            cout << "Disaster added successfully!" << endl;
        }
        else if (choice == 2)
        {
            if (disasters.empty())
            {
                cout << "No Disasters Recorded Yet" << endl;
            }

            for (int i = 0; i < disasters.size(); i++)
            {
                cout << "\nDisaster " << i + 1 << ":\n";
                disasters[i].display();
            }
        }

    } while (choice != 3);
    cout << "Program ended.\n";

    return 0;
}