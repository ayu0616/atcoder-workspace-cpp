#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin >> N;
    vl S(N), C(N);
    rep(i, N)
    {
        cin >> S[i] >> C[i];
    }
    map<ll, ll> mp;
    rep(i, N)
    {
        mp[S[i]] = C[i];
    }
    set<ll> q;
    rep(i, N)
    {
        q.insert(S[i]);
    }
    ll ans = 0;
    while (!q.empty())
    {
        ll s = *q.begin();
        q.erase(q.begin());
        ll cur = mp[s];
        ans += cur % 2;
        rep(i, 1, log2(cur) + 1)
        {
            if (cur & (1 << i))
            {
                ll si = s << i;
                mp[si]++;
                q.insert(si);
            }
        }
    }
    cout << ans << endl;
}
