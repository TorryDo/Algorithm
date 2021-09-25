#include <iostream>

#include <math.h>
#include <set>
#include <vector>
#include <queue>

using namespace std;

// ------------------------- FALSE ---------------------------------

bool edge[999][999];
bool vertex[999];
int step = 0;

void dfs(int n, int start, int end, int count)
{
    vertex[start] = false;

    for (int i = 1; i <= n; i++)
    {
        if (vertex[i] && edge[start][i])
        {
            count++;
            if (i == end && step < count)
            {
                step = count;
                break;
            }

            dfs(n, i, end, count);
        }
    }
}

int longestPath(int n, vector<vector<int>> edges, int u, int v)
{
    for (int i = 1; i <= n; i++)
        vertex[i] = true;
    for (auto vi : edges)
        edge[vi[0]][vi[1]] = true;

    dfs(n, u, v, 0);

    return step;
}

int main()
{
    vector<vector<int>> vvi = {{1, 2}, {1, 3}, {2, 1}};

    int n = 3;

    int u = 1;
    int v = 3;
    // answer = 1

    int ans = longestPath(n, vvi, u, v);

    cout << ans;

    return 0;
}