#ifndef DISASTER_H
#define DISASTER_H

#include <string>

class Disaster
{
private:
    std::string id;
    std::string type;
    std::string location;
    int severity;
    int affectedPeople;

public:
    // Passed strings by const reference to avoid unnecessary memory copying
    Disaster(const std::string& id,
             const std::string& type,
             const std::string& location,
             int severity,
             int affectedPeople);

    std::string getId() const;

    void display() const;
};

#endif
