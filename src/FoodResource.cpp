
#include "FoodResource.h"
#include <iostream>

using namespace std;
FoodResource::FoodResource(const string &resourceId,
                           const string &name,
                           int quantity,
                           int expiryDays)
    : Resource(resourceId, name, quantity)
{
    this->expiryDays = expiryDays;
}

void FoodResource::display() const
{
    cout << "Resource ID: " << getId() << endl;
    cout << "Resource Type: Food" << endl;
    cout << "Name: " <<     getName() << endl;
    cout << "Quantity: " << getQuantity()  << endl;
     cout << "Expires In (days): " << expiryDays << endl;
}