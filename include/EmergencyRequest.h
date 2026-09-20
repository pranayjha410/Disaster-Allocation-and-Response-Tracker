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
enum class RequestStatus
{
    PENDING,
    PROCESSED
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
    RequestStatus status;

public:
    EmergencyRequest(const std::string &requestId,
                     const std::string &personName,
                     const std::string &disasterId,
                     const std::string &need,
                     int peopleAffected,
                     Priority priority);

    std::string getId() const;

    Priority getPriority() const;

    std::string getPriorityText() const;

    RequestStatus getStatus() const;

    std::string getStatusText() const;

    void markProcessed();

    void display() const;
};

#endif