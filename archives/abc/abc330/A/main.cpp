#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N, L;
    cin >> N>>L;
    vl A(N);
    cin >> A;
    int ans = 0;
    rep(i, N) if (A[i] >= L) ans++;
    cout<<ans<<endl;
}
