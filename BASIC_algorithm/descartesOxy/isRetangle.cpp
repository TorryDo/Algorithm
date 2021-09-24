#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define roundThis(d) roundf(d * 1000) / 1000;

bool isRectangle(vector<vector<int>> p)
{
    double h = pow(p[0][0] - p[2][0], 2) + pow(p[0][1] - p[2][1], 2);
    double canhHuyenBinh = roundThis(h);


    double a1 = pow(p[0][0] - p[1][0], 2) + pow(p[0][1] - p[1][1], 2);
    double a2 = pow(p[1][0] - p[2][0], 2) + pow(p[1][1] - p[2][1], 2);

    double b1 = pow(p[2][0] - p[3][0], 2) + pow(p[2][1] - p[3][1], 2);
    double b2 = pow(p[3][0] - p[0][0], 2) + pow(p[3][1] - p[0][1], 2);

    if (a1 + a2 == canhHuyenBinh && b1 + b2 == canhHuyenBinh ) return true;

    return false;
}

int main()
{

    vector<vector<int>> v;
    vector<int> temp;

    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    v.push_back(temp);

    temp.clear();
    temp.push_back(2);
    temp.push_back(0);
    v.push_back(temp);

    temp.clear();
    temp.push_back(2);
    temp.push_back(1);
    v.push_back(temp);

    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    v.push_back(temp);

    cout << isRectangle(v);

    return 0;
}