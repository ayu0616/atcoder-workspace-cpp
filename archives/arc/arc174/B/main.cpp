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
    ll T;
    cin >> T;
    rep(T) {
        vl A(5), P(5);
        cin >> A >> P;
        ll A_sum = accumulate(all(A), 0LL);
        ll s = 0;
        rep(i, 5) { s += A[i] * (i + 1); }
        if (A_sum * 3 <= s) {
            cout << 0 << endl;
            continue;
        }
        ll q_5 = (3 * A_sum - s) / 2 + (3 * A_sum - s) % 2;
        ll q_4 = (3 * A_sum - s);
        ll ans1 = q_5 * P[4];
        ll ans2 = q_4 * P[3];
        q_5 = (3 * A_sum - s - 1) / 2 + (3 * A_sum - s - 1) % 2;
        ll ans3 = P[3] + q_5 * P[4];
        cout << min({ans1, ans2, ans3}) << endl;
    }
}
