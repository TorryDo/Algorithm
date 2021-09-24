#include <iostream>

#include <vector>
#include <math.h>

using namespace std;

int *insertionSort(int arr[], int n)
{

    int index, value;
    for (int i = 1; i < n; i++)
    {
        index = i;
        value = arr[i];

        while (index > 0 && arr[index - 1] > value)
        {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }

    return arr;
}

// vượt quá time limit. 11/12 TC passed

long long decorateRoom(int r, int g, int b)
{
    vector<int> arr = {r, g, b};
    sort(arr.begin(), arr.end());

    int count = 0;
    

    while (true)
    {
        if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == 1)
        {
            count++;
            break;
        }

        if (arr[2] < 2 || (arr[0] == arr[1] && arr[1] == 0))
            break;

        arr[2] -= 2;
        arr[1] -= 1;

        count++;

        if (arr[0] <= arr[1] && arr[1] <= arr[2])
            continue;

        sort(arr.begin(), arr.end());
    }

    return count;
}