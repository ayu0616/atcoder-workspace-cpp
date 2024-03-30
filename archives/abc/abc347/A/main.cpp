#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N, K;
    cin >> N >> K;
    vi A(N);
    cin >> A;
    vi ans;
    rep(i, N) {
        if (A[i] % K == 0) ans.push_back(A[i] / K);
    }
    cout << ans << endl;
}
