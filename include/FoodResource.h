#ifndef FOOD_RESOURCE_H
#define FOOD_RESOURCE_H

#include "Resource.h"

class FoodResource : public Resource
{
private:
    int expiryDays;

public:
    FoodResource(const std::string &resourceId,
                 const std::string &name,
                 int quantity,
                 int expiryDays);

    void display() const override;

};

#endif