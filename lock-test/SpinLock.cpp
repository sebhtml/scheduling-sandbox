
#include "SpinLock.h"

using namespace sebstd;
using namespace std;

SpinLock::
SpinLock()
    : m_locked(false)
{
}

SpinLock::
~SpinLock()
{
}

bool
SpinLock::
tryLock()
{
    bool expected(false);
    return m_locked.compare_exchange_weak(expected, true);
}

void
SpinLock::
unlock()
{
    m_locked = false;
}

void
SpinLock::
lock()
{
    bool expected(false);
    while (not m_locked.compare_exchange_weak(expected, true))
    {
        expected = false;
    }
}

