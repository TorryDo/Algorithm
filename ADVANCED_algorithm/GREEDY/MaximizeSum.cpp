#include <iostream>
#include <vector>

using namespace std;

int maximizeSum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int sum = 0;
    int n = arr.size() - 1;
    for (int i = 0; i <= n; i++)
    {
        sum += abs(arr[i] - arr[n - i]);
    }
    return sum;
}