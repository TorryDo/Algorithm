#include <iostream>

using namespace std;

void showBinary(int n, string s)
{
    if (n == 0)
        cout << s << " ";
    else
    {
        showBinary(n - 1, s + '0');
        showBinary(n - 1, s + '1');
    }
}

int main()
{

    int n;
    cin >> n;

    showBinary(n, "");

    return 0;
}