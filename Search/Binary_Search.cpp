#include <iostream>

using namespace std;

int binSearch(int a[], int size, int x)
{
    int l=0, r=(size-1) ;

    while( l < r )
    {
        int mid = (l+r)/2;
        if( a[mid] < x )
        {
            l = mid + 1;
        }else
        {
            r = mid;
        }

    }

    if( a[l] == x )
    {
        return l;
    }

    return -1;
}

int main()
{

    int n, x, a[1000];

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cin >> x;

    cout << binSearch(a,n,x);

    return 0;
}