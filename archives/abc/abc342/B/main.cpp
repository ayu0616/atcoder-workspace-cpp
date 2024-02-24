#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N, Q;
    cin >> N;
    vi P(N), idx(N + 1);
    cin >> P >> Q;
    rep(i, N) { idx[P[i]] = i; }
    rep(i, Q) {
        int a, b;
        cin >> a >> b;
        if (idx[a] < idx[b]) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    }
}
