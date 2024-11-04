#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <vector>
#include <stdexcept>

class Caretaker {
private:
    std::vector<Memento> history; ///< Holds all saved mementos.
    GameEnvironment* environment; ///< Reference to the game environment being managed.

public:
    /**
     * @brief Constructor for Caretaker.
     * 
     * @param env Reference to the game environment.
     */
    Caretaker(GameEnvironment* env) : environment(env) {}

    /**
     * @brief Saves the current state of the game environment to a memento.
     */
    void save() {
        history.push_back(environment->saveToMemento());
    }

    /**
     * @brief Restores the environment to a previously saved state.
     * 
     * @param index The index in the history vector to restore.
     * @throws std::out_of_range if the index is invalid.
     */
    void restore(int index) {
        if (index < 0 || index >= history.size()) {
            throw std::out_of_range("Invalid memento index.");
        }
        environment->restoreFromMemento(history[index]);
    }

    /**
     * @brief Gets the number of saved states.
     * 
     * @return int Number of mementos in history.
     */
    int getHistorySize() const {
        return history.size();
    }

    /**
     * @brief Clears all saved states.
     */
    void clearHistory() {
        history.clear();
    }
};

#endif // CARETAKER_H