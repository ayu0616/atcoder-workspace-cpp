#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;
// map<tuple<ll, ll, ll>, ll> mp;
ll children_count(ll current, ll d, ll N)
{
    // if (mp.count({current, d, N}))
    // {
    //     return mp[{current, d, N}];
    // }
    if (d < 0)
        return 0;
    ll from = current * powl(2, d);
    ll to = (current + 1) * powl(2, d) - 1;
    chmin(to, N);
    // return mp[{current, d, N}] = min(0, to - from + 1);
    return max(0, to - from + 1);
}

int main()
{
    ll T, N, X, K;
    cin >> T;
    rep(T)
    {
        cin >> N >> X >> K;
        ll ans = 0;
        ans += children_count(X, K, N);
        ll i = 1;
        ll prev = X;
        X /= 2;
        while (X)
        {
            ans += children_count(X, K - i, N) - children_count(prev, K - i - 1, N);
            X /= 2;
            i++;
        }
        cout << ans << endl;
    }
}
