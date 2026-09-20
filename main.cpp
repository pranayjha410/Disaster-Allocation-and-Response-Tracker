#include <iostream>
#include "Disaster.h"
#include "EmergencyRequest.h"
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

// g++ main.cpp src/Disaster.cpp src/EmergencyRequest.cpp -Iinclude -o disaster
//.\disaster
bool compareByPriority(const EmergencyRequest &a,
                       const EmergencyRequest &b)
{
    return static_cast<int>(a.getPriority()) >
           static_cast<int>(b.getPriority());
}

struct EmergencyRequestCompare
{
    bool operator()(const EmergencyRequest &a,
                    const EmergencyRequest &b) const
    {
        return static_cast<int>(a.getPriority()) < static_cast<int>(b.getPriority());
    }
};
int main()
{
    vector<Disaster> disasters;
    vector<EmergencyRequest> requests;
    int choice;

    priority_queue<EmergencyRequest,
                   vector<EmergencyRequest>,
                   EmergencyRequestCompare>
        emergencyQueue;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Disaster\n";
        cout << "2. View Disasters\n";
        cout << "3. Add Emergency Request\n";
        cout << "4. View Emergency Requests\n";
        cout << "5. Process Next Emergency\n";
        cout << "6. Exit\n";
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
        else if (choice == 3)
        {
            string requestId;
            string personName;
            string disasterId;
            string need;
            int peopleAffected;
            Priority priority;

            cin.ignore();
             bool exists;

            do
            {
                exists = false;

                cout << "Enter Request ID: ";
                cin >> requestId;

                for (int i = 0; i < requests.size(); i++)
                {
                    if (requests[i].getId() == requestId)
                    {
                        cout << "Request ID already exists.\n";
                        cout << "Please enter a different ID.\n";

                        exists = true;
                        break;
                    }
                }

            } while (exists);
            cin.ignore();
            cout << "Enter Your Name: ";
            getline(cin, personName);

            bool disasterExists;
            do
            {
                cout << "Enter Disaster ID this request is for: ";
                getline(cin, disasterId);
                disasterExists = false;

                for (int i = 0; i < disasters.size(); i++)
                {
                    if (disasters[i].getId() == disasterId)
                    {

                        disasterExists = true;
                        break;
                    }
                }
                if (!disasterExists)
                {
                    cout << "Disaster ID does not exist.\n";
                    cout << "Please enter a valid ID.\n";
                }
            } while (!disasterExists);

            cout << "Enter Need (e.g. Food, Medicine, Shelter): ";
            getline(cin, need);

            cout << "Enter People Affected: ";
            cin >> peopleAffected;

            while (cin.fail() || peopleAffected <= 0)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number: ";
                }
                else
                {
                    cout << "Please enter a positive number: ";
                }

                cin >> peopleAffected;
            }

            int priorityChoice;

            cout << "\nSelect Priority:\n";
            cout << "1. Low\n";
            cout << "2. Medium\n";
            cout << "3. High\n";
            cout << "4. Critical\n";
            cout << "Enter priority: ";

            cin >> priorityChoice;
            while (priorityChoice < 1 || priorityChoice > 4)
            {
                cout << "Invalid priority. Please enter a value between 1 and 4: ";
                cin >> priorityChoice;
            }
            switch (priorityChoice)
            {
            case 1:
                priority = Priority::LOW;
                break;

            case 2:
                priority = Priority::MEDIUM;
                break;

            case 3:
                priority = Priority::HIGH;
                break;

            case 4:
                priority = Priority::CRITICAL;
                break;
            }

            requests.push_back(EmergencyRequest(requestId, personName, disasterId, need, peopleAffected, priority));
            emergencyQueue.push(EmergencyRequest(requestId, personName, disasterId, need, peopleAffected, priority));
            cout << "Emergency Request added successfully!" << endl;
        }
        else if (choice == 4)
        {
            if (requests.empty())
            {
                cout << "No Emergency Requests Recorded Yet" << endl;
            }
            sort(requests.begin(), requests.end(), compareByPriority);
            for (int i = 0; i < requests.size(); i++)
            {
                cout << "\nRequest " << i + 1 << ":\n";
                requests[i].display();
            }
        }
        else if (choice == 5)
        {
            if (emergencyQueue.empty())
            {
                cout << "No pending emergencies to process.\n";
            }
            else
            {
                EmergencyRequest top = emergencyQueue.top();
                emergencyQueue.pop();

                cout << "\nProcessing highest priority emergency:\n";
                top.display();

                for (int i = 0; i < requests.size(); i++)
                {
                    if (requests[i].getId() == top.getId())
                    {
                        requests[i].markProcessed();
                        break;
                    }
                }

                cout << "Emergency request processed successfully!" << endl;
            }
        }

    } while (choice != 6);

    cout << "Program ended.\n";

    return 0;
}