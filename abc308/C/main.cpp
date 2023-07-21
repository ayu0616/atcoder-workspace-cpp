#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vector<long double> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<pair<long double, ll>> v(n);
    rep(i, n)
    {
        v[i].first = (long double)(b[i] / (a[i] + b[i]));
        v[i].second = i + 1;
    }
    sort(all(v));
    rep(i, n)
    {
        cout << v[i].second << " \n"[i == n - 1];
    }
}
