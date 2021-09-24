#include <iostream>

using namespace std;

int main()
{

    string str = "thisIsSoAwesome";
    string newStr = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            if(i!=0) newStr.append(" ");
            newStr += str[i] + 32;
        }
        else
        {
            newStr.push_back(str[i]);
        }
    }

    cout << newStr;

    return 0;
}