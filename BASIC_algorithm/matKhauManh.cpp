#include <iostream>

using namespace std;

bool checkStrongPassword(string password)
{
    if (password.length() < 6)
        return false;
    string p = "!@#$%^&*()-+";
    string s = password;
    bool kt1 = false;
    bool kt2 = false;
    bool kt3 = false;
    bool kt4 = false;
    for (int i = 0; i < password.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)  // A..Z
            kt1 = true;
        if (s[i] >= 97 && s[i] <= 122) // a..z
            kt2 = true;
        if (s[i] >= 48 && s[i] <= 57)  // 0..9
            kt4 = true;
        if (p.find(s[i]) != -1)
            kt3 = true;
    }
    return kt1 && kt2 && kt3 && kt4;
}