#include "Disaster.h"
#include <iostream>

using namespace std;

Disaster::Disaster(const string& id,
                   const string& type,
                   const string& location,
                   int severity,
                   int affectedPeople)
{
    this->id = id;
    this->type = type;
    this->location = location;
    this->severity = severity;
    this->affectedPeople = affectedPeople;
}

string Disaster::getId() const
{
    return id;
}

void Disaster::display() const
{
    cout << "Disaster ID: " << id << endl;
    cout << "Type: " << type << endl;
    cout << "Location: " << location << endl;
    cout << "Severity: " << severity << endl;
    cout << "Affected People: " << affectedPeople << endl;
}