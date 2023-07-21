#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

vector<pair<ll, ll>> ans, lr;
ll l, r;

void add(ll x, ll y, vector<pair<ll, ll>> &v)
{
    bool need_add = true;

    for (auto &p : v)
    {
        if (y < p.first || p.second < x)
            continue;
        else
        {
            p.first = min(p.first, x);
            p.second = max(p.second, y);
            need_add = false;
        }
    }
    if (need_add)
        v.push_back({x, y});
}

int main()
{
    ll n;
    cin >> n;
    rep(i, n)
    {
        cin >> l >> r;
        lr.push_back({l, r});
    }
    sort(lr.begin(), lr.end());
    for (auto p : lr)
    {
        add(p.first, p.second, ans);
    }
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}
