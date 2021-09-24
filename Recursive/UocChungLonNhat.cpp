#include <iostream>

using namespace std;

int timUocChungLonNhat(int a, int b)
{
    if (b == 0)
        return a;
    if (a % b == 0)
        return b;

    return timUocChungLonNhat(b, a % b);
}

int main()
{

    int a, b;
    cin >> a >> b;

    cout << timUocChungLonNhat(a, b);

    return 0;
}