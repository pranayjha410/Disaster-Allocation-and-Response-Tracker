#include <iostream>
using namespace std;

class Disaster {
public:
    string id;
    string type;
    string location;
    int severity;
    int affectedPeople;
};
int main() {
    Disaster d1;

    d1.id = "D001";
    d1.type = "Flood";
    d1.location = "Pune";
    d1.severity = 5;
    d1.affectedPeople = 1200;

    cout << "Disaster ID: " << d1.id << endl;
    cout << "Type: " << d1.type << endl;
    cout << "Location: " << d1.location << endl;
    cout << "Severity: " << d1.severity << endl;
    cout << "Affected People: " << d1.affectedPeople << endl;

    return 0;
}