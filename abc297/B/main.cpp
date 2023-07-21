#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

string s;

int main()
{
    cin >> s;
    vector<int> x;
    bool ok = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            x.push_back(i);
    }
    ok = ok && (x[0] % 2 != x[1] % 2);
    bool f = false;
    for (auto v : s)
    {
        if (v == 'R')
            f = !f;
        if (v == 'K')
            ok = ok && f;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
