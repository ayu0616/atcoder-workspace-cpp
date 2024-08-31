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
    vi A(N);
    vs S(N);
    rep(i, N) { cin >> A[i] >> S[i]; }
    int cr = -1, cl = -1;
    int ans =0;
    rep(i, N) {
        if (S[i] == "R") {
            if (cr != -1) {
                ans += abs(A[i] - cr);
            }
            cr = A[i];
        } else if (S[i] == "L") {
            if (cl != -1) {
                ans += abs(A[i] - cl);
            }
            cl = A[i];
        }
    }
    cout << ans << endl;
}
