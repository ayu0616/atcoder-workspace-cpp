#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n, q, x;
    vector<ll> a, sa, X, X_sorted;
    map<ll, ll> ans;
    cin >> n >> q;
    vector_in(a, n);
    vector_in(X, q);
    sort(a.begin(), a.end());
    sa.push_back(0);
    rep(i, n)
    {
        sa.push_back(sa[i] + a[i]);
    }
    X_sorted = X;
    sort(X_sorted.begin(), X_sorted.end());

    ll index = 0;
    rep(i, q)
    {
        x = X_sorted[i];
        while (index < n && a[index] <= x)
        {
            index++;
        }
        ans[x] = 2 * x * index - 2 * sa[index] + sa[n] - x * n;
    }
    rep(i, q)
    {
        cout << ans[X[i]] << endl;
    }
}
