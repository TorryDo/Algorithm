#include <iostream>

#include <vector>

using namespace std;

bool vertex[100001];
bool edge[1001][1001];
bool kt = false;

void dfs(int u, int v, int n)
{
    vertex[u] = false;

    for (int i = 1; i <= n; i++)
    {
        if (edge[u][i] && vertex[i])
        {

            if (i == v)
                kt = true;

            dfs(i, v, n);
        }
    }
}

bool check(int n, vector<vector<int>> e, int u, int v)
{

    for (int i = 0; i <= n; i++)
        vertex[i] = true;

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++)
    //         edge[i][j] = false;

    for (int i = 0; i < e.size(); i++)
        edge[e[i][0]][e[i][1]] = true;

    dfs(u, v, n);

    return kt;
}

vector<vector<int>> generateVector()
{
    vector<vector<int>> e;

    vector<int> temp = {1, 2};

    e.push_back(temp);

    temp = {2, 3};
    e.push_back(temp);

    return e;
}

int main()
{

    int n = 3;

    vector<vector<int>> e = generateVector();

    cout << "vector<vector<int>> = " << e[0][0] << e[0][1] << e[1][0] << e[1][1] << endl;

    int u = 1;
    int v = 3;

    if (check(n, e, u, v))
        cout << "result = true";
    else
        cout << "result = false";
}