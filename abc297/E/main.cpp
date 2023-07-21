#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n;
ll k, a[10], ans[200010];

int main()
{
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(0);
    ll cnt = 0;
    while (!q.empty())
    {
        ll x = q.top();
        q.pop();
        if (cnt == 0 || ans[cnt - 1] != x)
        {
            ans[cnt++] = x;
            rep(i, n) q.push(x + a[i]);
        }
        if (cnt == k + 1)
            break;
    }
    cout << ans[k] << endl;
}