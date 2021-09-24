#include <iostream>

using namespace std;

// phù hợp với dataset trung bình, xấu nhất : n

int *shellSort(int a[], int n)
{
    int j;

    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i++)
        {
            int temp = a[i];
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }

    return a;
}

int main()
{

    int n, a[9999];

    // cin >> n ;
    n = 9;

    for (int i = 0; i < n; i++)
    {
        // cin >> a[i];
        a[i] = n - i;
    }

    int *tempa = shellSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << tempa[i] << " ";
    }
}