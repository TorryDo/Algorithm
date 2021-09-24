#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool insideCircle(vector<int> point, vector<int> center, int radius)
{
    double t1 = pow(center[1] - point[1], 2);
    double t2 = pow(center[0] - point[0], 2);

    return t1 + t2 <= radius * radius ? true : false;  // ở đây t1+t2 chưa căn bậc 2 nên radius phải ^2
}