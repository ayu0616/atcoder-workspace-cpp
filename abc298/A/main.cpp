#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    string s;
    cin >> n >> s;
    bool a = false, b = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
        {
            a = true;
        }
        if (s[i] == 'x')
        {
            b = true;
        }
    }
    if (a && !b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
