//
// Created by Jean-Michel Frouin on 06/10/2024.
//

#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

namespace Core {

    /**
     * \class CMutex
     * \brief A class to handle mutex operations.
     */
    class CMutex {
    public:
        /**
         * \brief Default constructor.
         * Initializes the mutex.
         */
        CMutex();

        /**
         * \brief Destructor.
         * Destroys the mutex.
         */
        ~CMutex();

        /**
         * \brief Locks the mutex.
         * \return True if the mutex was successfully locked, false otherwise.
         */
        bool Lock();

        /**
         * \brief Unlocks the mutex.
         * \return True if the mutex was successfully unlocked, false otherwise.
         */
        bool UnLock();

    private:
        pthread_mutex_t mMutex; /**< The pthread mutex. */
    };

} // Core

#endif //MUTEX_H