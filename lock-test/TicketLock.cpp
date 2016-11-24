
#include "TicketLock.h"

using namespace sebstd;
using namespace std;

TicketLock::
TicketLock()
    : m_front(0)
    , m_back(0)
{
}

TicketLock::
~TicketLock()
{
}

bool
TicketLock::
tryLock()
{
    return false;
}

void
TicketLock::
unlock()
{
    ++m_front;
}

void
TicketLock::
lock()
{
    std::uint64_t myTicket(m_back);

    while (not m_back.compare_exchange_weak(myTicket, myTicket + 1))
    {
        myTicket = m_back;
    }

    while (myTicket != m_front)
    {
    }
}

