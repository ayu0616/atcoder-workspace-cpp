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
    int N, X;
    cin >> N >> X;
    vi S(N);
    cin >> S;
    ll ans = 0;
    rep(i, N)
    {
        if (S[i] <= X)
            ans += S[i];
    }
    cout << ans << endl;
}
