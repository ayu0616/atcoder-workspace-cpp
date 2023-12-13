#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M;
    cin >> N >> M;
    vl A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    ll ans = 0;
    rep(i, N)
    {
        auto it1 = lower_bound(all(A), A[i]);
        auto it2 = lower_bound(all(A), A[i] + M);
        ll cnt = it2 - it1;
        if (cnt > ans)
        {
            ans = cnt;
        }
    }
    cout << ans << endl;
}
