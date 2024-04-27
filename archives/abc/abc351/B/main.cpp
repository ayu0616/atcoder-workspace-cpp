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
    vs A(N), B(N);
    cin >> A >> B;
    rep(i, N) rep(j, N) {
        if (A[i][j] != B[i][j]) {
            cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }
    }
}
