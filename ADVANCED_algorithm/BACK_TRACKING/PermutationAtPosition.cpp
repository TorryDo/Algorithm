#include <iostream>
#include <vector>

using namespace std;

int road[999];
bool check[999];

int amount = 0;

vector<int> ans;

void printAns(int n)
{
    for (int i = 1; i <= n; i++)
        ans.push_back(road[i]);
}

void dequy(int prev, int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            check[i] = true;
            road[prev] = i;

            if (prev == n)
            {
                amount++;
                if (amount == k)
                {
                    printAns(n);
                    return;
                }
            }
            else
                dequy(prev + 1, n, k);

            check[i] = false;
        }
    }
}

vector<int> nthPermutation(int n, int k)
{
    dequy(1, n, k);
    return ans;
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> v = nthPermutation(n, k);

    return 0;
}
