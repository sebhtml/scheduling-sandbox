
#ifndef TicketLock_H
#define TicketLock_H

#include <atomic>
#include <cinttypes>

namespace sebstd
{
    class TicketLock;
}

class sebstd::TicketLock
{
public:

    TicketLock();

    ~TicketLock();

    bool tryLock();

    void unlock();

    void lock();

private:

    std::atomic<std::uint64_t> m_front;
    std::atomic<std::uint64_t> m_back;
};

#endif
