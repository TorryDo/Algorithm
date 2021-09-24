// #include <iostream>
// #include <string>

// using namespace std;

// string upThis(string str)
// {
//     if (str[0] >= 97 && str[0] <= 122)
//         str[0] -= 32;

//     int position = str.find(" ");
//     while (position >= 0)
//     {
//         if (str[position + 1] >= 96 && str[position + 1] <= 122)
//             str[position + 1] -= 32;

//         position = str.find(" ", position + 1);
//     }

//     return str;
// }

// int main()
// {
//     string s;
//     cout << "Input S: " << endl;
//     getline(cin, s);
//     string newS = upThis(s);
//     cout << "Output S: " << newS;
// }

#include <iostream>
#include <math.h>
#include <cstring>
#include <string>

using namespace std;

char proper(char s[])
{
    if (s[0] == ' ')
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ' && s[i + 1] != ' ')
                s[i + 1] -= 32;
        }
    }
    else
    {
        s[0] = s[0] - 32;
        for (int j = 1; j < strlen(s); j++)
        {
            if (s[j] == ' ' && s[j + 1] != ' ')
                s[j + 1] -= 32;
        }
    }
}

int main()
{
    char s[100];
    string str;
    cout << "Input S: " << endl;

    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        s[i] = str[i];
    }

    proper(s);
    cout << "Output S: " << s;
}