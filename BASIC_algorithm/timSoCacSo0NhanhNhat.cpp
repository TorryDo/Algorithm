#include <iostream>

using namespace std;

long long numberZeroDigits(long long n)
{
    long long count = 0;
    long long lt = 5;

    while (lt <= n)
    {
        count += n / lt;
        lt *= 5;
    }

    return count;
}