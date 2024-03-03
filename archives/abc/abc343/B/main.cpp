#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N;
    cin >> N;
    vvi A(N, vi(N));
    cin >> A;
    rep(i, N) {
        vi ans;
        rep(j, N) {
            if (A[i][j] == 1) {
                ans.push_back(j + 1);
            }
        }
        cout << ans << endl;
    }
}
