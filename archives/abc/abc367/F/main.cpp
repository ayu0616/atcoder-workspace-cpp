#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/segtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, Q;
    cin >> N >> Q;
    vi A(N), B(N);
    cin >> A >> B;
    vl A_sum(N + 1), B_sum(N + 1);
    rep(i, N) {
        A_sum[i + 1] = A_sum[i] + hash<string>()(to_string(A[i]));
        B_sum[i + 1] = B_sum[i] + hash<string>()(to_string(B[i]));
    }
    while (Q--) {
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        --l;
        --L;
        if (r - l != R - L) {
            cout << "No" << endl;
            continue;
        }
        if (A_sum[r] - A_sum[l] == B_sum[R] - B_sum[L]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
