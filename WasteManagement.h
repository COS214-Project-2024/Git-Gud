#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"

class WasteManagement : public Utility {
private:
    int handlingCapacity;  // Capacity to handle waste

public:
    WasteManagement(int capacity, int maintenanceCost, int HandlingCap);
    virtual ~WasteManagement() = default;

    void provideService() override;
    
    int getHandlingCapacity() const;
};

#endif  // WASTEMANAGEMENT_H