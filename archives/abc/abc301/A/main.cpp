#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int a=0, t=0;
    char first = 'N';
    rep(i, n)
    {
        if (s[i] == 'A')
            a++;
        else
            t++;
        if (a * 2 == n && first == 'N')
            first = 'A';
        if (t * 2 == n && first == 'N')
            first = 'T';
    }
    if (a == t)
        cout << first << endl;
    else if (a > t)
        cout << 'A' << endl;
    else
        cout << 'T' << endl;
}
