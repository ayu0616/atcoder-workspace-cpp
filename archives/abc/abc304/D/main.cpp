#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll w, h, n, A, B;
vl p, q;
set<ll> a, b;
map<pii, ll> m;

int main()
{
    cin >> w >> h >> n;
    p.resize(n);
    q.resize(n);
    rep(i, n) cin >> p[i] >> q[i];
    cin >> A;
    rep(i, A)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }
    a.insert(w);
    cin >> B;
    rep(i, B)
    {
        ll x;
        cin >> x;
        b.insert(x);
    }
    b.insert(h);

    rep(i, n)
    {
        auto ix = a.lower_bound(p[i]);
        auto iy = b.lower_bound(q[i]);
        m[{*ix, *iy}]++;
    }

    ll min_ans = n, max_ans = 0;
    if (m.size() < (A + 1) * (B + 1))
        min_ans = 0;
    for (auto [k, v] : m)
    {
        chmin(min_ans, v);
        chmax(max_ans, v);
    }

    cout << min_ans << " " << max_ans << endl;
}
