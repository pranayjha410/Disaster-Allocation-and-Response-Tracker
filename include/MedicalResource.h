#ifndef MEDICAL_RESOURCE_H
#define MEDICAL_RESOURCE_H
#include "Resource.h"

class MedicalResource : public Resource{
private:
    bool requiresPrescription;
public:
      MedicalResource(const std::string &resourceId,
                 const std::string &name,
                 int quantity,
                 bool requiresPrescription);

                 void display() const override;
};

#endif