#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)

vector<vector<int>> spiralNumbers(int n)
{
    vector<vector<int>> v;
    vector<int> b;
    FOR(_, 0, n)
    b.push_back(1);
    FOR(_, 0, n)
    v.push_back(b);

    int start = 0;
    int end = n - 1;
    int k = 0;

    int pow = n * n;

    while (k < pow)
    {
        if (k < pow)
            for (int ltr = start; ltr <= end; ltr++)
                v[start][ltr] = ++k;

        if (k < pow)
            for (int ttb = start + 1; ttb <= end; ttb++)
                v[ttb][end] = ++k;

        if (k < pow)
            for (int rtl = end - 1; rtl >= start; rtl--)
                v[end][rtl] = ++k;

        if (k < pow)
            for (int btt = end - 1; btt >= start + 1; btt--)
                v[btt][start] = ++k;

        start++;
        end--;
    }
    return v;
}

int main()
{

    cout << "nhap n : ";

    int n;
    cin >> n;

    vector<vector<int>> v = spiralNumbers(n);

    for (auto p : v)
    {
        for (auto i : p)
            cout << i << ", ";
        cout << endl;
    }

    return 0;
}