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
    vs A(N);
    cin >> A;
    vs ans = A;
    rep(i, N) rep(j, N) {
        if (min({i, j, N - 1 - i, N - 1 - j}) % 4 == 0) {
            ans[j][N - i - 1] = A[i][j];
        } else if (min({i, j, N - 1 - i, N - 1 - j}) % 4 == 1) {
            ans[N - i - 1][N - j - 1] = A[i][j];
        } else if (min({i, j, N - 1 - i, N - 1 - j}) % 4 == 2) {
            ans[N - j - 1][i] = A[i][j];
        } else {
            ans[i][j] = A[i][j];
        }
    }
    rep(i, N) { cout << ans[i] << endl; }
}
