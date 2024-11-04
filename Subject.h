/**
 * @file Subject.h
 * @brief Header file for the Subject class, implementing the observer pattern.
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>

#include "Citizen.h"
#include "ChangeData.h"

//forward declaration:
class Citizen;

/**
 * @class Subject
 * @brief Class representing the subject in the observer pattern.
 * @details This class maintains a list of observers (citizens) and provides methods to manage them.
 */
class Subject{

    private:
        /// @brief List of observers (citizens) observing this subject.
        std::vector<Citizen*> observerList;

    protected:
        

    public:
        /// @brief Static list of all citizens.
        static std::vector<Citizen*> allCitizens;

        /**
         * @brief Attach an observer (citizen) to the subject.
         * @param observer Pointer to the Citizen to be added as an observer.
         */
        void attach(Citizen* observer);

        /**
         * @brief Detach an observer (citizen) from the subject.
         * @param observer Pointer to the Citizen to be removed from observers.
         */
        void detach(Citizen* observer);

        /**
         * @brief Notify all observers about a change.
         * @param changeData Data related to the change to notify observers.
         */
        void notify(ChangeData changeData);

        /**
         * @brief Add a citizen to the simulation.
         * @param newCitizen Pointer to the new Citizen to be added.
         */
        void addCitizenToSimulation(Citizen* newCitizen);

        /**
         * @brief Remove a citizen from the simulation.
         * @param citizen Pointer to the Citizen to be removed.
         */
        void removeCitizenFromSimulation(Citizen* citizen);

        /**
         * @brief Get the size of the observer list.
         * @return int The number of observers currently attached.
         */
        int getObserverListSize();

        /**
         * @brief Get the total number of citizens.
         * @return int The total number of citizens.
         */
        int getNumCitizens();

        /**
         * @brief Get the list of current observers.
         * @return std::vector<Citizen*> List of pointers to observers (citizens).
         */
        std::vector<Citizen*> getObserverList();

};


#endif // SUBJECT_H