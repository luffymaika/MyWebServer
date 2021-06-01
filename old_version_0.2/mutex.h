#ifndef MUTEX.H
#define MUTEX.H

#include <pthread.h>
#include <assert.h>
#include <sys/types.h>
#include "util.h"

namespace luffy {
class MutexLock : public nocopyable {
private:
    pthread_mutex_t mutex_;
    pid_t holder_;

public:
    MutexLock() : holder_(0){
        pthread_mutex_init(&mutex_, NULL);
    }

    ~MutexLock() {
        assert(holder_ == 0);
        pthread_mutex_destroy(&mutex_);
    }

    void lock() {
        pthread_mutex_lock(&mutex_);
        holder_ = gettid();
    }


};

}

#endif