//
// Created by Jean-Michel Frouin on 06/10/2024.
//

#include "Mutex.h"

namespace Core {

    CMutex::CMutex() {
        pthread_mutex_init(&mMutex, nullptr);
    }

    CMutex::~CMutex() {
        pthread_mutex_destroy(&mMutex);
    }

    bool CMutex::Lock() {
        return pthread_mutex_lock(&mMutex) == 0;
    }

    bool CMutex::UnLock() {
        return pthread_mutex_unlock(&mMutex) == 0;
    }

} // Core