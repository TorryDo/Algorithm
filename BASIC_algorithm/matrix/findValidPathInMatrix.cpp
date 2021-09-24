#include <iostream>
#include <vector>

using namespace std;

bool findPath(vector<vector<int>> matrix)
{
    int column = matrix[0].size();
    int row = matrix.size();

    int columnOne = -1;
    int rowOne = -1;
    int count = 2;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] == 1)
            {
                columnOne = j;
                rowOne = i;
            }
        }
    }
    if (columnOne == -1 && rowOne == -1)
    {
        return false;
    }

    while (count <= column * row)
    {
        if (rowOne + 1 >= 0 && rowOne + 1 < row && matrix[rowOne + 1][columnOne] == count)
        {
            count++;
            rowOne++;
        }
        else if (rowOne - 1 >= 0 && rowOne - 1 < row && matrix[rowOne - 1][columnOne] == count)
        {
            count++;
            rowOne--;
        }
        else if (columnOne - 1 >= 0 && columnOne - 1 < column && matrix[rowOne][columnOne - 1] == count)
        {
            count++;
            columnOne--;
        }
        else if (columnOne + 1 >= 0 && columnOne + 1 < column && matrix[rowOne][columnOne + 1] == count)
        {
            count++;
            columnOne++;
        }
        else
        {
            return false;
        }
    }

    return true;
}