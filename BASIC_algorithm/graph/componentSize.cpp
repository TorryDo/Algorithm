#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// FINISHED

// đề yc đếm số đỉnh mà từ đỉnh đã cho có thể chạm tới

set<int> si;

void addConnection(vector<vector<bool>> vvb, int peak)
{
    for (int i = 0; i < vvb.size(); ++i)
        if (vvb[peak][i] && !si.count(i))
        {
            si.insert(i);
            addConnection(vvb, i);
        }
    
}

int componentSize(vector<vector<bool>> matrix, int peak)
{
    si.insert(peak);
    addConnection(matrix, peak);

    return si.size();
}