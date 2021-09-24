#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> v) {}

int numberOfToys(vector<int> arr, int k)
{
    sort(arr);

    int count = 0;
    int n = 0;

    for (int price : arr)
    {
        if (count + price <= k)
        {
            count += price;
            n++;
        }
        else
        {
            return n;
        }
    }
    return -1;
}