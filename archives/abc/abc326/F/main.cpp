#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll solve(vl &v, ll x)
{
    map<ll, ll> memo;
    ll n = v.size();
    rep(i, 1 << (n / 2))
    {
        ll t = 0;
        rep(k, n / 2)
        {
            if (i >> k & 1)
                t += v[k];
            else
                t -= v[k];
        }
        memo[t] = i;
    }
    rep(i, 1 << (n - (n / 2)))
    {
        ll t = 0;
        rep(k, n - (n / 2))
        {
            if (i >> k & 1)
                t += v[k + n / 2];
            else
                t -= v[k + n / 2];
        }
        if (memo.count(x - t))
        {
            return (ll)i << (n / 2) | memo[x - t];
        }
    }
    return -1;
}

int main()
{
    ll N, X, Y;
    cin >> N >> X >> Y;
    vl even, odd;
    rep(i, N)
    {
        ll a;
        cin >> a;
        if (i % 2 == 0)
        {
            even.push_back(a);
        }
        else
        {
            odd.push_back(a);
        }
    }

    ll even_ways = solve(even, Y);
    ll odd_ways = solve(odd, X);

    if (even_ways == -1 || odd_ways == -1)
    {
        cout << "No" << endl;
        return 0;
    }

    string ans = "";
    vi all_ways;
    rep(i, N)
    {
        if (i % 2 == 0)
            all_ways.push_back(even_ways >> (i / 2) & 1 ? 1 : 3);
        else
            all_ways.push_back(odd_ways >> (i / 2) & 1 ? 0 : 2);
    }
    int dir = 0;
    rep(i, N)
    {
        if ((dir + 1) % 4 == all_ways[i])
            ans += 'L';
        else
            ans += 'R';
        dir = all_ways[i];
    }
    cout << "Yes" << endl;
    cout << ans << endl;
}
