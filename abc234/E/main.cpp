#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

set<ll> gen_tousa()
{
    set<ll> res;
    for (int digit = 1; digit <= 18; digit++)
    {
        for (int d = -9; d <= 9; d++)
        {
            for (int i = 0; i < 10; i++)
            {
                vector<int> tmp(digit, 0);
                bool ok = true;
                rep(j, digit)
                {
                    if (j == 0)
                    {
                        tmp[0] = i;
                    }
                    else
                    {
                        int x = tmp[j - 1] + d;
                        if (x < 0 || x > 9)
                        {
                            ok = false;
                            break;
                        }
                        tmp[j] = x;
                    }
                }
                if (ok && tmp.back() != 0)
                {
                    ll num = 0;
                    rep(j, digit) num += tmp[j] * (ll)pow(10, j);
                    // cout << num << endl;
                    res.insert(num);
                }
            }
        }
    }
    return res;
}

int main()
{
    ll x;
    cin >> x;
    auto tousa = gen_tousa();
    auto ans = *tousa.lower_bound(x);
    cout << ans << endl;
}
