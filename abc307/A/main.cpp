#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int n;
vi a, ans;

int main()
{
    cin >> n;
    a.resize(7 * n);
    rep(i, 7 * n) cin >> a[i];
    int cnt = 0;
    while (n)
    {
        n--;
        int tmp = 0;
        rep(i, 7)
        {
            tmp += a[i + cnt];
        }
        ans.push_back(tmp);
        cnt += 7;
    }

    print(ans);
}
