#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int findSquareSide(vector<int> x, vector<int> y)
{
    int x1 = pow(abs(x[1] - x[0]), 2);
    int y1 = pow(abs(y[1] - y[0]), 2);
    int l1 = x1 + y1;

    int x2 = pow(abs(x[2] - x[0]), 2);
    int y2 = pow(abs(y[2] - y[0]), 2);
    int l2 = x2 + y2;

    int x3 = pow(abs(x[3] - x[0]), 2);
    int y3 = pow(abs(y[3] - y[0]), 2);
    int l3 = x3 + y3;

    if (l1 == l2)
        return l1;
    else
        return l3;
}