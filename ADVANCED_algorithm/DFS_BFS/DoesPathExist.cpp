#include <iostream>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

bool vertex[9999];
bool edge[999][999];
bool kt = false;

void dfs(int start, int end, int n)
{
    vertex[start] = false;

    for (int i = 1; i <= n; ++i)
    {
        if (edge[start][i] && vertex[i])
        {
            if (i == end)
                kt = true;
            dfs(i, end, n);
        }
    }
}

bool findPath(int n, vector<vector<int>> vvi, int start, int end)
{
    for (int i = 1; i <= n; ++i)
        vertex[i] = true;
    for (auto vi : vvi)
        edge[vi[0]][vi[1]] = true;

    dfs(start, end, n);

    return kt;
}

int main()
{

    int n = 5;
    vector<vector<int>> vvi = {{1, 2}, {2, 4}, {4, 3}, {3, 5}, {5, 1}, {4, 5}};
    int start = 1;
    int end = 5;

    cout << findPath(n, vvi, start, end);

    return 0;
}