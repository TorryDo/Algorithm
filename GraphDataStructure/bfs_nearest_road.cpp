#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool opened[100001];  
int travel[100001];
bool edge[1001][1001];

int bfs(int start, int end, int n)
{
    queue<int> kyu;

    kyu.push(start);
    opened[start] = false;

    while (!kyu.empty())
    {
        int front = kyu.front();

        for (int i = 1; i <= n; i++)
        {
            if (edge[front][i] && opened[i])
            {
                opened[i] = false;
                kyu.push(i);

                travel[i] = travel[front] + 1;
                if (i == end)
                    break;
            }
        }

        kyu.pop();
    }

    return travel[end];
}

int graphFunction(int n, vector<vector<int>> v, int start, int end)
{

    for (int i = 0; i <= n; i++)
    {
        opened[i] = true;
        travel[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            edge[i][j] = false;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        edge[v[i][0]][v[i][1]] = true;
        edge[v[i][1]][v[i][0]] = true;
    }

    int result = bfs(start, end, n);
    return (result == 0) ? -1 : result;
}