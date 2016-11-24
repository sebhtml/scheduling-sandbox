
#include "SpinLock.h"
#include <iostream>

using namespace std;
using namespace sebstd;

template <typename LockType>
void testLock(const std::size_t threads, const std::size_t lockEvents);

int main(int argc, char ** argv)
{
    auto i(0);

    const string app(argv[i++]);

    if (argc != 2)
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
        testLock<SpinLock>(threads, lockEvents);
    }

    return 0;
}


template <typename LockType>
void testLock(const std::size_t threads, const std::size_t lockEvents)
{
    for (auto i = 0; i < threads; ++i)
    {
        for (auto j = 0; j < lockEvents; ++j)
        {
        }
    }
}
