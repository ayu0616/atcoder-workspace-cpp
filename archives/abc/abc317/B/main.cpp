#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    set<int> s;
    rep(i, n) s.insert(a[i]);
    auto m = *min_element(all(a));
    rep2(i, m + 1, m + n + 2)
    {
        if (!s.count(i))
        {
            cout << i << endl;
            return 0;
        }
    }
}
