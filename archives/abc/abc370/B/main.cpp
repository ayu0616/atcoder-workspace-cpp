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
    vvi A(N, vi(N));
    rep(i, N) {
        rep(j, i + 1) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    int now = 0;
    rep(i, N) {
        if (now >= i) {
            now = A[now][i];
        } else {
            now = A[i][now];
        }
    }
    cout << now + 1 << endl;
}
