#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool checkEqualFrequency(vector<int> v)
{
    map<int, int> m;
    for (auto const &p : v)
        m[p]++;

    pair<int, int> last = *m.begin();
    for (auto p : m)
        if (last.second != p.second)
            return false;
            
    return true;
}