#ifdef HASSAKU_DEBUG
#define _GLIBCXX_DEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, Q, l, r;
    string S;
    cin >> N >> Q >> S;
    vl sum(N + 1);
    rep(i, N)
    {
        sum[i + 1] = sum[i] + (S[i+1] == S[i] ? 1 : 0);
    }
    rep(i, Q)
    {
        cin >> l >> r;
        cout << sum[r - 1] - sum[l - 1] << endl;
    }
}
