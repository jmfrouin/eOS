//
// Created by Jean-Michel Frouin on 06/10/2024.
//

#include <gtest/gtest.h>
#include <Core/Mutex.h>
#include <thread>

class CMutexTest : public ::testing::Test {
protected:
    Core::CMutex mutex;
};

TEST_F(CMutexTest, LockUnlock) {
    EXPECT_TRUE(mutex.Lock());
    EXPECT_TRUE(mutex.UnLock());
}

TEST_F(CMutexTest, ThreadSafety) {
    int counter = 0;
    auto increment = [&]() {
        for (int i = 0; i < 1000; ++i) {
            mutex.Lock();
            ++counter;
            mutex.UnLock();
        }
    };

    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    EXPECT_EQ(counter, 2000);
}