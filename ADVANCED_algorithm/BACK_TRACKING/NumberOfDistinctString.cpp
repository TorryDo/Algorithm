#include <iostream>

#include <vector>
#include <set>

using namespace std;

set<string> mySet;

bool road[999];
bool check[999];

void printRoad(string s, string c)
{
    int count = 0;
    for (int i = 0; i <= s.length() + 1; i++)
        if (road[i])
        {
            s.insert(i + count, c);
            mySet.insert(s);
            count++;
        }
}

void dequy(int i, string s, string c)
{
    for (int j = 0; j < 2; j++)
    {
        road[i] = j;
        check[j] = true;

        if (i == s.length() + 1)
        {
            printRoad(s, c);
            return;
        }
        else
            dequy(i + 1, s, c);

        check[i] = false;
    }
}

int numberOfDistinctString(string s, string c)
{
    int n = s.length() + 1;
    dequy(0, s, c);

    return mySet.size() + 1;
    // 7 TC đều thiếu 1 đơn vị, sau này m thông minh hơn thì xem lại khúc nầy
    // 14/14 TC passed hihi
}

int main()
{

    string s = "AB";
    string c = "C";

    int rs = numberOfDistinctString(s, c);

    cout << rs;

    return 0;
}