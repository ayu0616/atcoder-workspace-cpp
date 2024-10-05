#include <cmath>
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
    double S, T;
    cin >> N >> S >> T;
    vector<double> A(N), B(N), C(N), D(N);
    rep(i, N) { cin >> A[i] >> B[i] >> C[i] >> D[i]; }
    vi v(N);
    iota(all(v), 0);
    double ans = INT_INF;
    do {
        for (ll st = 0; st < 1ll << N; st++) {
            ll cur_x = 0, cur_y = 0;
            double t = 0;
            rep(i, N) {
                ll j = v[i];
                if (st >> i & 1) {
                    double d = sqrtl((A[j] - cur_x) * (A[j] - cur_x) + (B[j] - cur_y) * (B[j] - cur_y));
                    t += d / S;
                    double d2 = sqrtl((C[j] - A[j]) * (C[j] - A[j]) + (D[j] - B[j]) * (D[j] - B[j]));
                    t += d2 / T;
                    cur_x = C[j];
                    cur_y = D[j];
                } else {
                    double d = sqrtl((C[j] - cur_x) * (C[j] - cur_x) + (D[j] - cur_y) * (D[j] - cur_y));
                    t += d / S;
                    double d2 = sqrtl((A[j] - C[j]) * (A[j] - C[j]) + (B[j] - D[j]) * (B[j] - D[j]));
                    t += d2 / T;
                    cur_x = A[j];
                    cur_y = B[j];
                }
            }
            ans = min(ans, t);
        }
    } while (next_permutation(all(v)));
    cout << ans << endl;
}
