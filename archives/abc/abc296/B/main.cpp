#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

vector<char> a, b;

int main()
{
    for (int i = 'a'; i <= 'h'; i++)
    {
        a.push_back((char)i);
    }
    for (int i = '8'; i >= '1'; i--)
    {
        b.push_back((char)i);
    }
    vector<string> s;
    string tmp;
    while (cin >> tmp)
    {
        s.push_back(tmp);
    }
    int n = 8;
    rep(i, n) rep(j, n)
    {
        if (s[i][j] == '*')
        {
            cout << (char)a[j] << (char)b[i] << endl;
        }
    }
}
