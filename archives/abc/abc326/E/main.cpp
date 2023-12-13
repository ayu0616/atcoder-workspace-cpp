#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin >> N;
    vl A(N);
    rep(i, N) cin >> A[i];
    mint ans = 0;
    vector<mint> p(N + 1);
    mint p_sum = 1;
    p[0] = 1;
    rep(i, N)
    {
        p[i + 1] = p_sum / N;
        ans += (p[i + 1] * A[i]);
        p_sum += p[i + 1];
    }
    cout << ans << endl;
}
