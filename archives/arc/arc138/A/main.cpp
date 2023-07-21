#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] -= i;
    vi b(n);
    rep(i, n) b[i] = i;
    sort(b.begin(), b.end(), [&](int i, int j)
         { return a[i] < a[j]; });

    int ans = 1e9;
    int max_in_init = -1;
    for (int bi : b)
    {
        if (bi < k)
            max_in_init = max(max_in_init, bi);
        else if (max_in_init != -1 && a[max_in_init] < a[bi])
            ans = min(ans, bi - max_in_init);
    }
    cout << (ans != (int)1e9 ? ans : -1) << endl;
}
