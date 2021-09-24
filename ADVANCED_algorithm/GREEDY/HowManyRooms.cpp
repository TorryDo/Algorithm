#include <iostream>
#include <vector>

using namespace std;

// UNCHECKED

int mettingRoom(vector<int> s, vector<int> e)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (e[i] > e[j])
            {
                swap(e[j], e[i]);
                swap(s[j], s[i]);
            }
        }
    }

    int count = 0;
    int index = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (e[index] <= s[i])
        {
            count++;
            index = i;
        }
        else
            continue;
    }
    return count + 1;
}