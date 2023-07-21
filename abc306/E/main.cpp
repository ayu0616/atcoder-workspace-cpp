#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

#include <iostream>
using namespace std;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vl x(q), y(q), a(n, 0);
    rep(i, q) cin >> x[i] >> y[i];
    rep(i, q) x[i]--;

    ll f = 0;

    multiset<ll> b_not, b_k;
    rep(i, n - k)
    {
        b_not.insert(0);
    }
    rep(i, k)
    {
        b_k.insert(0);
    }

    rep(i, q)
    {
        ll before = a[x[i]], after = y[i];
        if (b_k.find(before) != b_k.end())
        {
            b_k.erase(b_k.find(before));
            f -= before;
        }
        else
        {
            b_not.erase(b_not.find(before));
        }

        b_not.insert(after);

        while (b_k.size() < k)
        {
            auto it = b_not.end();
            it--;
            ll m = *it;
            b_not.erase(b_not.find(m));
            b_k.insert(m);
            f += m;
        }

        if (!b_k.empty() && !b_not.empty())
        {
            auto ik = b_k.begin();
            auto in = b_not.end();
            in--;
            ll mk = *ik, mn = *in;
            while (mk < mn)
            {
                b_k.erase(ik);
                b_not.erase(in);
                b_k.insert(mn);
                b_not.insert(mk);
                f += mn - mk;
                ik = b_k.begin();
                in = b_not.end();
                in--;
                mk = *ik, mn = *in;
            }
        }

        a[x[i]] = y[i];
        cout << f << endl;
    }
}
