
#ifndef SpinLock_H
#define SpinLock_H

#include <atomic>

namespace sebstd
{
    class SpinLock;
}

class sebstd::SpinLock
{
public:

    SpinLock();

    ~SpinLock();

    bool tryLock();

    void unlock();

    void lock();

private:

    std::atomic<bool> m_locked;
};

#endif
