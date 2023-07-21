#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool compare(string big, string small)
{
    bool res = false;
    if (small.length() < big.length())
    {
        res |= small == big.substr(0, small.length());
    }
    rep(i, min(small.length(), big.length()))
    {
        if (small[i] < big[i])
        {
            res = true;
            break;
        }
        else if (small[i] > big[i])
        {
            break;
        }
    }
    return res;
}

int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> n >> s;
        string ans = "No";
        rep2(i, 1, n)
        {
            if (s[0] < s[i])
            {
                ans = "Yes";
                break;
            }
        }
        rep2(p, 1, n)
        if (s[0]==s[p] && compare(s.substr(p), s.substr(0, p)))
        {
            ans = "Yes";
            break;
        }
        cout << ans << endl;
    }
}
