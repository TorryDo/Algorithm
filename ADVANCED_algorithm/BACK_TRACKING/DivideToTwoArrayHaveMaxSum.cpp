#include <iostream>
#include <vector>

using namespace std;

// sai . passed 9/14 TC

using namespace std;

int maximalMultiple(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size() - 1;

    int sum1 = 0;
    int sum2 = 0;

    if (arr[0] >= 0)
    {
        // full positive
        sum1 = arr[n];
        sum2 = arr[n - 1];

        for (int i = n - 2; i >= 0; i--)
            if (sum1 > sum2)
                sum2 += arr[i];
            else
                sum1 += arr[i];
    }
    else if (arr[n] <= 0)
    {
        // full negative
        sum1 = arr[0];
        sum2 = arr[1];
        for (int i = 2; i <= n; i++)
            if (sum1 > sum2)
                sum1 += arr[i];
            else
                sum2 += arr[i];
    }
    else
    {
        // both
        sum1 = arr[0];
        sum2 = arr[1];

        for (int i = 2; i <= n; i++)
            if (sum1 > sum2)
                sum2 += arr[i];
            else
                sum1 += arr[i];
    }

        return sum1 * sum2;
    
}