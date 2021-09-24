#include <iostream>

using namespace std;

// đpt th xấu nhất = n*log(n)  ->  phù hợp dataset lớn

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// vector<int> sortByHeight(vector<int> a)
// {
//     vector<int> b = a;
//     sort(a.begin(), a.end());
//     int h = 0;
//     for (int i = 0; i < a.size(); i++)
//         if (a[i] != -1)
//         {
//             h = i;
//             break;
//         }
//     for (int i = 0; i < a.size(); i++)
//         if (b[i] != -1)
//         {
//             b[i] = a[h];
//             h++;
//         }
//     return b;
// }

void quickSort(int a[], int l, int r)
{

    int pivot = a[(l + r) / 2];
    int i = l;
    int j = r;

    while (i < j)
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

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
    {
        quickSort(a, i, r);
    }
    if (j > l)
    {
        quickSort(a, l, j);
    }
}


int main()
{

    int arr[9999];
    int n;
    // cin >> n;
    n = 9;
    for (int i = 0; i < n; i++)
    {
        // cin >> arr[i];
        arr[i] = n - i;
    }

    quickSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}