#include <iostream>
#include <queue>
#include <set>
#include <math.h>

using namespace std;

bool vertex[99999];
int step[99999];

void BFS(vector<vector<bool>> vvb, int peak)
{
    queue<int> kyu;
    kyu.push(peak);
    vertex[peak] = 0;

    while (!kyu.empty())
    {
        int prev = kyu.front();

        for (int i = 0; i < vvb.size(); ++i)
            if (vvb[prev][i] && vertex[i])
            {
                kyu.push(i);
                step[i] = step[prev] + 1;
                vertex[i] = 0;
            }

        kyu.pop();
    }
}

vector<int> bfsDistancesUnweightedGraph(vector<vector<bool>> vvb, int startVertex)
{
    for (int i = 0; i < vvb.size(); ++i)
        vertex[i] = 1;

    BFS(vvb, startVertex);

    vector<int> vi;
    for (int i = 0; i < vvb.size(); ++i)
        vi.push_back(step[i]);

    return vi;
}