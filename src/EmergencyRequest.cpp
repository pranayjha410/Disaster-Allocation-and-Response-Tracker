#include "EmergencyRequest.h"
#include <iostream>

using namespace std;

EmergencyRequest::EmergencyRequest(const string& requestId,
                                   const string& personName,
                                   const string& disasterId,
                                   const string& need,
                                   int peopleAffected,
                                   Priority priority)
{
    this->requestId = requestId;
    this->personName = personName;
    this->disasterId = disasterId;
    this->need = need;
    this->peopleAffected = peopleAffected;
    this->priority = priority;
    this->status = RequestStatus::PENDING;
}

string EmergencyRequest::getId() const
{
    return requestId;
}

Priority EmergencyRequest::getPriority() const
{
    return priority;
}


string EmergencyRequest::getPriorityText() const
{
    switch (priority)
    {
        case Priority::LOW:
            return "Low";

        case Priority::MEDIUM:
            return "Medium";

        case Priority::HIGH:
            return "High";

        case Priority::CRITICAL:
            return "Critical";
    }

    return "Unknown";
}
RequestStatus EmergencyRequest::getStatus() const{
    return status;
}   

string EmergencyRequest::getStatusText() const{
      switch (status)
    {
        case RequestStatus::PENDING:
            return "Pending";

        case RequestStatus::PROCESSED:
            return "Processed";
    }

    return "Unknown";
}
void EmergencyRequest::markProcessed()
{
    status = RequestStatus::PROCESSED;
}

void EmergencyRequest::display() const
{
    cout << "Request ID: " << requestId << endl;
    cout << "Requested By: " << personName << endl;
    cout << "Disaster ID: " << disasterId << endl;
    cout << "Need: " << need << endl;
    cout << "People Affected: " << peopleAffected << endl;
    cout << "Priority: " << getPriorityText() << endl;
    cout << "Status: " << getStatusText() << endl;
}