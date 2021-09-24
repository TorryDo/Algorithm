#include <iostream>

#include <set>
#include <vector>

int main()
{

    return 0;
}

std::vector<std::vector<int>> uniqueRows(std::vector<std::vector<int>> matrix)
{
    std::set<std::vector<int>> sv;
    std::vector<std::vector<int>> vv;

    for (std::vector<std::vector<int>>::iterator it = matrix.begin(); it != matrix.end(); it++)
    {
        if (!sv.count(*it))
        {
            sv.insert(*it);
            vv.push_back(*it);
        }
    }
    return vv;
}
