
#include "SpinLock.h"
#include "TicketLock.h"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;
using namespace sebstd;

template <typename LockType>
void testLockInThreads(const std::size_t threads, const std::size_t lockEvents);

template <typename LockType>
void testLock(const std::size_t lockEvents, LockType & lock);

int main(int argc, char ** argv)
{
    auto i(0);

    const string app(argv[i++]);

    if (argc != 4)
    {
        cout << "Usage:";
        cout << endl;
        cout << app << " sebstd::SpinLock|sebstd::TicketLock|std::mutex threads lockEvents";
        cout << endl;
        cout << endl;

        cout << "Example:";
        cout << endl;
        cout << app << " sebstd::SpinLock 4 100000";
        cout << endl;
        return 0;
    }

    const string type(argv[i++]);

    const auto threads(std::atoi(argv[i++]));
    const auto lockEvents(std::atoi(argv[i++]));

    if (type == "sebstd::SpinLock")
    {
        testLockInThreads<SpinLock>(threads, lockEvents);
    }
    else if (type == "sebstd::TicketLock")
    {
        testLockInThreads<TicketLock>(threads, lockEvents);
    }
    else if (type == "std::mutex")
    {
        testLockInThreads<mutex>(threads, lockEvents);
    }

    return 0;
}


template <typename LockType>
void testLockInThreads(const std::size_t threads, const std::size_t lockEvents)
{
    LockType lock;

    vector<thread> myThreads;

    auto myFunction = testLock<LockType>;

    for (auto i = 0; i < threads; ++i)
    {
        thread myThread(myFunction, lockEvents, std::ref(lock));

        myThreads.push_back(std::move(myThread));
    }

    for (auto i = 0; i < threads; ++i)
    {
        myThreads[i].join();
    }
}


template <typename LockType>
void testLock(const std::size_t lockEvents, LockType & lock)
{
    for (auto i = 0; i < lockEvents; ++i)
    {
        lock.lock();
        // Critical section...
        // Do important stuff here.
        lock.unlock();
    }
}
