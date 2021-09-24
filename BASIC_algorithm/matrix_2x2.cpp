#include <iostream>
#include <vector>
#include <set>

using namespace std;

int differentSquares(vector<vector<int>> matrix)
{
    set<vector<int>> vs;
    for (int i = 0; i < matrix.size() - 1; i++)
    {
        for (int j = 0; j < matrix[0].size() - 1; j++)
        {
            vector<int> tempV = {matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1]};
            vs.insert(tempV);
        }
    }

    return vs.size();
}
