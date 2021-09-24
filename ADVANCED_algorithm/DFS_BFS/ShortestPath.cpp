#include <iostream>
#include <math.h>

#include <vector>
#include <set>
#include <queue>

using namespace std;

// Hãy viết hàm trả về khoảng cách của đường đi ngắn nhất từ đỉnh 1 tới tất cả các đỉnh.
// với n = 4    =>     1->1, 1->2, 1->3, 1->4

bool vertex[9999];
bool edge[999][999];
int step[9999];

void bfs(int start, int end, int n)
{
    queue<int> kyu;
    kyu.push(start);
    vertex[start] = false;

    while (!kyu.empty())
    {
        int front = kyu.front();

        for (int i = 1; i <= n; ++i)
        {
            if (edge[front][i] && vertex[i])
            {

                kyu.push(i);
                vertex[i] = false;

                step[i] = step[front] + 1;

                if (i == end)
                    break;
            }
        }

        kyu.pop();
    }
}

void setUp(vector<vector<int>> vvi, int n)
{
    for (int i = 1; i <= n; ++i)
        vertex[i] = true;

    for (auto vi : vvi)
    {
        edge[vi[0]][vi[1]] = true;
        edge[vi[1]][vi[0]] = true;
    }
}

vector<int> shortestPath(int n, vector<vector<int>> vvi)
{

    setUp(vvi, n);
    bfs(1, n, n);

    vector<int> ans;
    for (int i = 1; i <= n; i++)
        ans.push_back(step[i]);

    return ans;
}

int main()
{

    vector<vector<int>> vvi = {{1, 2}, {2, 3}, {3, 4}};
    int n = 4;

    auto vi = shortestPath(n, vvi);

    for (auto i : vi)
    {
        cout << i << endl;
    }

    return 0;
}