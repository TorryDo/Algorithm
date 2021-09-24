#include <iostream>
#include <vector>
#include <set>

using namespace std;

int res = 0;

// chưa làm xong trên web

void back(vector<int> arr, int n, int k, int sum)
{
    if (sum == k)
    {
        res++;
    }
    for (int i = n; i < arr.size(); i++)
    {
        if (sum + arr[i] > k)
            continue;
        if (i > n && arr[i] == arr[i - 1])
            continue;

        back(arr, i + 1, k, sum + arr[i]);
    }
}
int combinationSum(vector<int> arr, int k)
{
    int sum = 0;

    sort(arr.begin(), arr.end());

    back(arr, 0, k, 0);
    return res;
}

int main()
{

    vector<int> arr = {1, 1, 2, 4, 3};
    int k = 4;

    return 0;
}