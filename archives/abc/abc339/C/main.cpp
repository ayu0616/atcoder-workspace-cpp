#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vl A(N);
    cin >> A;
    ll min_cur = 0, cur = 0;
    rep(i, N) {
        cur += A[i];
        chmin(min_cur, cur);
    }
    cout << cur-min_cur << endl;
}
