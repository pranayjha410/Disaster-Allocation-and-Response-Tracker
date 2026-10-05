#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource
{
private:
    std::string resourceId;
    std::string name;
    int quantity;

public:
    Resource(const std::string& resourceId,
             const std::string& name,
             int quantity);

    virtual void display() const = 0;

    virtual ~Resource() = default;

    std::string getId() const;
    std::string getName() const;
    int getQuantity() const; // inbuilt type


    void reduceQuantity(int amount); 
};

#endif