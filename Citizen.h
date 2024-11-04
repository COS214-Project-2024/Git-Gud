/**
 * @file Citizen.h
 * @brief Header file for the Citizen class, representing a citizen in the system.
 */

#ifndef CITIZEN_H
#define CITIZEN_H

#include "SatisfactionLevel.h"
#include "Subject.h"
#include "ChangeData.h"

class SatisfactionLevel;

/**
 * @class Citizen
 * @brief Class representing a citizen with attributes such as job status and satisfaction level.
 * @details This class includes methods to handle changes in the environment that affect the citizen's state.
 */
class Citizen{

    private:
        /// @brief Pointer to the satisfaction level of the citizen.
        SatisfactionLevel* satisfactionLevel; 

        /// @brief Indicates whether the citizen currently has a job.
        bool hasJob;

    public:

        /**
         * @brief Default constructor for the Citizen class.
         */
        Citizen();

        /**
         * @brief Destructor for the Citizen class.
         */
        virtual ~Citizen();

        /**
         * @brief Constructor that initializes the Citizen with a job status.
         * @param hasJob Boolean indicating if the citizen has a job.
         */
        Citizen(bool hasJob);

        /**
         * @brief Update the citizen's state based on change data.
         * @param changeData ChangeData object containing information about the change.
         */
        virtual void update(ChangeData changeData);

        /**
         * @brief Get the job status of the citizen.
         * @return bool indicating if the citizen has a job.
         */
        bool getHasJob();

        /**
         * @brief Set the job status of the citizen.
         * @param jobStatus Boolean indicating the new job status.
         */
        void setJobStatus(bool jobStatus);

        //void update(ChangeData changeData);
        /**
         * @brief Handle changes in the tax rate that affect the citizen.
         * @param newTaxRate Float representing the new tax rate.
         */
        void handleTaxChange(float newTaxRate);

        /**
         * @brief Handle the event of a new building being constructed.
         * @param BuildingNum Float representing the building number or identifier.
         */
        void handleBuildingConstructed(float BuildingNum);

        /**
         * @brief Handle the service provided by a utility or service provider.
         * @param UtilityFloat Float representing the utility value or identifier.
         */
        void handleServiceProvided(float UtilityFloat);

        
        /// @brief Returns the satifaction level of the citizen
        /// @return SatisfactionLevel*
        SatisfactionLevel* getSatisfactionLevel();

        /// @brief sets the satifaction level of the citizen
        /// @param satisfactionLevel Pointer to the new SatisfactionLevel object.
        void setSatisfactionLevel(SatisfactionLevel* satisfactionLevel);

        /**
         * @brief Update the satisfaction level of the citizen.
         */
        void updateSatisfactionLevel();

};


#endif // CITIZEN_H