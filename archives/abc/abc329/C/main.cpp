#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vi a('z' - 'a' + 1, 0);
    int c = 1;
    char pre = S[0];
    a[pre - 'a'] = 1;
    rep(i, 1, N)
    {
        if (pre == S[i])
        {
            c++;
        }
        else
        {
            a[pre - 'a'] = max(a[pre - 'a'], c);
            c = 1;
            pre = S[i];
        }
    }
    a[pre - 'a'] = max(a[pre - 'a'], c);
    int ans = 0;
    rep(i, 'z' - 'a' + 1)
    {
        ans += a[i];
    }
    cout << ans << endl;
}
