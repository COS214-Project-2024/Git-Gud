#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "Utility.h"
#include "ResourceManager.h"
#include <string>

class UtilityFactory {
    protected:
    // Helper method to adjust resources in ResourceManager
    void adjustResource(const std::string& resourceType, int amount) {
        ResourceManager::getInstance()->addResource(resourceType, amount);
    }

    void spendBudget(int amount) {
        ResourceManager::getInstance()->spendBudget(amount);
    }

    public:
        UtilityFactory(){};
        virtual ~UtilityFactory(){}

        virtual Utility* createUtility(int capacity, int maintenanceCost) = 0;
};

#endif // UTILITYFACTORY_H