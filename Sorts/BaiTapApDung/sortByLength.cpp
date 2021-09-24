#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

vector<string> sortByLength(vector<string> inputArray)
{
    string temp;
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < inputArray.size() - 1; ++i)
            if (inputArray[i].length() > inputArray[i + 1].length())
            {
                temp = inputArray[i];
                inputArray[i] = inputArray[i + 1];
                inputArray[i + 1] = temp;
                isSorted = false;
            }
    }

    return inputArray;
}

int main()
{

    vector<string> TC1 = {"abc", "", "aaa", "a", "zz"};

    TC1 = sortByLength(TC1);

    for (int i = 0; i < TC1.size(); ++i)
        cout << TC1[i] << endl;

    return 0;
}