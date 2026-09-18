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

            cout << "Enter Disaster ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Type (e.g. Flood): ";
            getline(cin,type);
            cout << "Enter Location: ";
            getline(cin,location);
            cout << "Enter Severity (1-10): ";
            cin >> severity;
            cout << "Enter Affected People: ";
            cin >> affectedPeople;

            disasters.push_back(Disaster(id, type, location, severity, affectedPeople));
    cout << "Disaster added successfully!"<<endl;
        }
        else if (choice == 2)
        {
            if(disasters.empty()){
                cout<<"No Disasters Recorded Yet"<<endl;
            }
            
            for (int i = 0; i < disasters.size(); i++) {
                 cout << "\nDisaster " << i + 1 << ":\n";
        disasters[i].display();
    }
        }

    } while (choice != 3);
    cout << "Program ended.\n";

    return 0;
}