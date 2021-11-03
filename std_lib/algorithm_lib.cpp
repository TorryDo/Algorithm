#include <iostream>

#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <list>
#include <vector>

using namespace std;

vector<int> *getUnorderedListofInt()
{
    vector<int> *intList;
    *intList = {1, 3, 2, 4, 7, 3, 77, 3, 66, 3, 653, 56, 3, 2, 0, 1, 9};
    return *intList;
}

int main()
{

    vector<int> *vectorInts = getUnorderedListofInt();

    // int arrayInts[17] = {1, 3, 2, 4, 7, 3, 77, 3, 66, 3, 653, 56, 3, 2, 0, 1, 9};
    // int arraySize = sizeof(arrayInts) / sizeof(arrayInts[0]);
    // sort(vectorInts.begin(), vectorInts.end());
    // sort(&arrayInts[0], &arrayInts[16]);

    for (auto i : vectorInts)
    {
        cout << i << " ";
    }

    return 0;
}
