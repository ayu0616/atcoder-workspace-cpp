#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(n), ans;
    rep(i, n) cin >> a[i];
    rep(i, n - 1)
    {
        int a1 = a[i];
        int a2 = a[i + 1];
        if (a1 > a2)
        {
            int tmp = a1;
            while (tmp > a2)
            {
                ans.push_back(tmp);
                tmp--;
            }
        }
        else if (a1 < a2)
        {
            int tmp = a1;
            while (tmp < a2)
            {
                ans.push_back(tmp);
                tmp++;
            }
        }
    }
    ans.push_back(a[n - 1]);
    rep(i, ans.size()) cout << ans[i]<<" \n"[i==ans.size()-1];
}
