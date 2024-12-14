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
    ll N, S;
    cin >> N >> S;
    vl A(N);
    cin >> A;
    ll asum = accumulate(all(A), 0LL);
    S %= asum;
    rep(i, N) { A.push_back(A[i]); }
    vl B(2 * N + 1);
    rep(i, 2 * N) { B[i + 1] = B[i] + A[i]; }
    rep(i, N) {
        ll l = i, r = 2 * N;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (B[m] - B[i] <= S) {
                l = m;
            } else {
                r = m;
            }
        }
        if (B[l] - B[i] == S) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
