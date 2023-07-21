#if !__INCLUDE_LEVEL__
#include __FILE__

ll n, C;

int main()
{
    cin >> n >> C;
    vector<pair<ll, ll>> event;
    rep(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        event.emplace_back(a - 1, c);
        event.emplace_back(b, -c);
    }
    sort(event.begin(), event.end());
    ll ans = 0;
    ll current = 0;
    ll t = 0;
    for (auto [day, cost] : event)
    {
        ans += min(current, C) * (day - t);
        current += cost;
        t = day;
    }
    cout << ans << endl;
}

#else

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#endif