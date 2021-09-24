#include <iostream>
#include <vector>
#include <set>

using namespace std;

int arr[999999];

int fib(int n)
{
    if (arr[n] != NULL)
    {
        return arr[n];
    }
    int result;
    if (n == 1 || n == 2)
        result = 1;
    if (n == 3)
        result = 2;
    if (n == 4)
        result = 3;
    if (n > 4)
    {
        result = fib(n - 1) * fib(n - 2) + fib(n - 3);
    }

    arr[n] = result;

    return arr[n];
}

int fibLikeSq(int n)
{
    return fib(n);
}