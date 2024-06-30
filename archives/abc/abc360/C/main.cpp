#include <queue>
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
    ll N;
    cin >> N;
    vl A(N), W(N);
    cin >> A >> W;
    vvi B(N);
    rep(i, N) {
        A[i]--;
        B[A[i]].push_back(W[i]);
    }
    ll ans = 0;
    rep(i, N) {
        sort(all(B[i]));
        if (B[i].size() > 0) {
            rep(j, B[i].size() - 1) { ans += B[i][j]; }
        }
    }
    cout << ans << endl;
}
