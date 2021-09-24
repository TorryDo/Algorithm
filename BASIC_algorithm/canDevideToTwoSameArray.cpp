#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool beautifulArray(vector<int> arr)
{
    vector<int> vi;
    vi.push_back(arr[0]);
    for (int i = 1; i < arr.size(); ++i)
        vi.push_back(vi[i - 1] + arr[i]);
    for (int i = 1; i < arr.size(); ++i)
        if (vi[i - 1] == vi.back() - vi[i])
            return true;

    return false;
}