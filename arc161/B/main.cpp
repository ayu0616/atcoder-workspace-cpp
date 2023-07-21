#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

string toBinary(ll n)
{
    string r;
    while (n != 0)
    {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

ll to_ll(string s)
{
    ll ret = 0;
    ll base = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        ret += (s[i] - '0') * base;
        base *= 2;
    }
    return ret;
}

int main()
{
    int t;
    ll n;
    cin >> t;

    rep(i, t)
    {
        cin >> n;
        if (n < 7)
        {
            cout << -1 << endl;
            continue;
        }
        string bin;
        int len;
        int cnt = 0, loop_cnt = 0;
        while (cnt < 3)
        {
            cnt = 0;
            bin = toBinary(n - loop_cnt);
            len = bin.length();
            rep(j, len)
            {
                if (bin[j] == '1')
                {
                    cnt++;
                }
            }
            loop_cnt++;
        }
        string ans = "";
        cnt = 0;
        rep(j, len)
        {
            if (cnt < 3)
            {
                ans.push_back(bin[j]);
            }
            else
            {
                ans.push_back('0');
            }
            if (bin[j] == '1')
            {
                cnt++;
            }
        }
        cout << to_ll(ans) << endl;
    }
}
