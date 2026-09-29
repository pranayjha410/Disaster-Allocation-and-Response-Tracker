#include "ShelterResource.h"
#include <iostream>

using namespace std;

ShelterResource::ShelterResource(const string& resourceId,
                                 const string& name,
                                 int quantity,
                                 int capacity)
    : Resource(resourceId, name, quantity)
{
    this->capacity = capacity;
}

void ShelterResource::display() const
{
    cout << "Resource ID: " << getId() << endl;
    cout << "Resource Type: Shelter" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Quantity: " << getQuantity() << "Units"<<endl;
    cout << "Capacity Per Unit: " << capacity << " people" << endl;
}