#ifndef SHELTER_RESOURCE_H
#define SHELTER_RESOURCE_H

#include "Resource.h"

class ShelterResource : public Resource
{
private:
    int capacity;

public:
    ShelterResource(const std::string& resourceId,
                    const std::string& name,
                    int quantity,
                    int capacity);

    void display() const override;
};

#endif