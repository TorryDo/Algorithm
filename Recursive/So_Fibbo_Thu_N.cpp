#include <iostream>

using namespace std;

long long getSoFiboThuN(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return getSoFiboThuN(n - 1) + getSoFiboThuN(n - 2);
}

int main()
{

    int n, *valueHolder = 0;
    cin >> n;

    cout << getSoFiboThuN(n);

    return 0;
}