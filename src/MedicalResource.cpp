#include "MedicalResource.h"
#include <iostream>

using namespace std;

MedicalResource::MedicalResource(const string &resourceId,
                                 const string &name,
                                 int quantity,
                                 bool requiresPrescription)
    : Resource(resourceId, name, quantity)
{
    this->requiresPrescription = requiresPrescription;
}

void MedicalResource::display() const
{
    cout << "Resource ID: " << getId() << endl;
    cout << "Resource Type: Medical" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Quantity: " << getQuantity() << endl;
    cout << "Requires Prescription: "
         << (requiresPrescription ? "Yes" : "No") << endl;
}