#include <iostream>

#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

int main()
{
    set<int> si;
    si.insert(2);
    bool b = si.count(1);

    printf(b ? "true" : "false");

    return 0;
}