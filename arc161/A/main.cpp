#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    vl a1, a2, s;
    rep(i, n / 2 + 1)
    {
        a1.push_back(a[i]);
    }
    rep2(i, n / 2 + 1, n)
    {
        a2.push_back(a[i]);
    }
    rep(i, n / 2)
    {
        s.push_back(a1[i]);
        s.push_back(a2[i]);
    }
    s.push_back(a1.back());

    string ans = "Yes";

    rep(i, n)
    {
        if (i % 2 == 0)
            continue;
        if (s[i - 1] < s[i] && s[i] > s[i + 1])
            continue;
        ans = "No";
        break;
    }

    cout << ans << endl;
}
