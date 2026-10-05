#include "Resource.h"
#include <iostream>

using namespace std;

Resource::Resource(const string& resourceId,
                   const string& name,
                   int quantity)
{
    this->resourceId = resourceId;
    this->name = name;
    this->quantity = quantity;
}

string Resource::getId() const
{
    return resourceId;
}
string Resource::getName() const
{
    return name;
}
int Resource::getQuantity() const
{
    return quantity;
}
void Resource::reduceQuantity(int amount)
{
    quantity -= amount;
}



