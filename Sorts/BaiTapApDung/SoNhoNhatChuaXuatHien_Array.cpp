#include <iostream>

using namespace std;

// Hãy đưa ra số tự nhiên nhỏ nhất chưa xuất hiện trong dãy.

void quickSort(int a[], int l, int r)
{
    int i = l, j = r;
    int pivot = a[(l + r) / 2];

    while (i < j)
    {
        while (a[i] < pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
        quickSort(a, i, r);
    if (j > l)
        quickSort(a, 0, j);
}

int solve(int a[], int n)
{
    quickSort(a, 0, n - 1);

    if (a[0] > 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] - a[i - 1] > 1)
        {
            return a[i - 1] + 1;
        }
    }
    return a[n - 1] + 1;
}

int main()
{
    int arr[99999];
    int n;
    // cin >> n;
    n = 9;
    for (int i = 0; i < n; i++)
    {
        // cin >> arr[i];
        arr[i] = i;
    }

    int num = solve(arr, n);

    cout << num;
}