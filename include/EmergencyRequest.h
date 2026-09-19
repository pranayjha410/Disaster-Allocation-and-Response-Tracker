#ifndef EMERGENCY_REQUEST_H
#define EMERGENCY_REQUEST_H

#include <string>

enum class Priority
{
    LOW,
    MEDIUM,
    HIGH,
    CRITICAL
};

class EmergencyRequest
{
private:
    std::string requestId;
    std::string personName;
    std::string disasterId;
    std::string need;
    int peopleAffected;
    Priority priority;

public:
    EmergencyRequest(const std::string& requestId,
                     const std::string& personName,
                     const std::string& disasterId,
                     const std::string& need,
                     int peopleAffected,
                     Priority priority);

    std::string getId() const;

    Priority getPriority() const;

    std::string getPriorityText() const;

    void display() const;
};

#endif