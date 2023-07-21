#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<pair<ll, ll>> bc(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> bc[i].second >> bc[i].first;
    sort(all(a));
    sort(all(bc));
    reverse(all(bc));
    ll s = 0;
    rep(i, n) s += a[i];
    vector<ll> ans_v(n + 1, 0);
    ans_v[0] = s;
    int cnt = 0;
    deque<ll> q;
    rep(i, n)
    {
        if (q.empty() && cnt < m)
        {
            for (int j = 0; j < min(n - i, bc[cnt].second); j++)
            {
                q.push_back(bc[cnt].first);
            }
            cnt++;
        }
        else if (q.empty())
        {
            ans_v[i + 1] = ans_v[i];
            continue;
        }
        ans_v[i + 1] = ans_v[i] - a[i] + q.front();
        q.pop_front();
    }
    ll ans = 0;
    rep(i, n + 1) ans = max(ans, ans_v[i]);
    cout << ans << endl;
}
