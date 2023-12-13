#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vi a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    vvi g(n, vi());
    rep(i, m){
        g[b[i]-1].push_back(a[i]-1);
    }
    set<int> saikyou;
    rep(i, n)
    {
        if (g[i].size() == 0)
            saikyou.insert(i + 1);
    }
    cout << (saikyou.size() == 1 ? *saikyou.begin() : -1) << endl;
}
