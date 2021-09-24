#include <iostream>

#include <math.h>
#include <set>
#include <vector>

// UNCHECKED

using namespace std;

// bool isTournament(int n, std::vector<int> from, std::vector<int> to)
// {
//     int f[11] = {};
//     for (int i = 0; i < from.size(); i++)
//     {
//         f[from[i]]++;
//         f[to[i]]++;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (f[i] != n - 1)
//             return false;
//     }
//     return true;
// }

bool isTournament(int n, vector<int> fromV, vector<int> toV)
{
    bool a[1000][1000];
    vector<int> temp;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
        v.push_back(temp);

    for (int i = 0; i < fromV.size(); i++)
    {
        v[fromV[i]].push_back(toV[i]);

        a[fromV[i]][toV[i]] = true;
        a[toV[i]][fromV[i]] = true;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!a[i][j] && i != j || a[i][j] && i == j) // condition sau đc tạo ra để loại TH {1} & {1}
                return false;

    return true;
}

int main()
{
    // 5 -> false
    // vector<int> fromV = {2, 1, 3, 4, 4, 4};
    // vector<int> toV = {3, 2, 1, 3, 2, 1};

    // 10 -> false
    // vector<int> fromV = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<int> toV = {2, 3, 4, 5, 6, 7, 8, 9, 10, 1};

    // 1  -> false
    // vector<int> fromV = {1};
    // vector<int> toV = {1};

    // 5 -> true
    vector<int> fromV = {2, 1, 3, 4, 4, 4, 1, 2, 3, 4};
    vector<int> toV = {3, 2, 1, 3, 2, 1, 5, 5, 5, 5};

    cout << isTournament(5, fromV, toV);
    return 0;
}