#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)
{
    int butt = arr.size() - 1;

    int counter = d;

    while (counter--)
    {
        int rightSide = arr[butt];
        arr[butt] = arr[0];

        for (int i = 0; i < butt - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[butt - 1] = rightSide;
    }

    return arr;
}

int main()
{
    vector<int> vt = {1, 2, 3, 4, 5};

    for (auto i : rotateLeft(4, vt))
    {
        cout << i << " ";
    }

    return 0;
}