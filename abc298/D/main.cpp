#include "../../lib.hpp"

// #define MOD 1000000007
#define MOD 998244353

ll q, ans;
int type, x;
deque<int> dq;

ll pow_mod(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    cin >> q;
    dq.push_front(1);
    ans = 1;
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            dq.push_back(x);
            ans *= 10;
            // cout << ans << endl;
            ans += x;
            // cout << ans << endl;
            ans %= MOD;
        }
        else if (type == 2)
        {
            x = dq.front();
            dq.pop_front();
            ans -= x * pow_mod(10, dq.size());
            ans %= MOD;
        }
        else
        {
            // ll siz = dq.size();
            // ll ans = 0;
            // rep(i, siz)
            // {
            //     ans += dq[i] * pow_mod(10, i);
            //     ans %= MOD;
            // }
            if (ans < 0)
                ans += MOD;
            cout << ans << endl;
        }
        // cout << type << " : ";
        // cout<<ans<<endl;
    }
}
