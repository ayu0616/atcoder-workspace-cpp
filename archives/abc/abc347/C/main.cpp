#include <cassert>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    auto start = clock();
    cout << fixed << setprecision(18);
    ll N, A, B;
    cin >> N >> A >> B;
    vl D(N);
    cin >> D;
    ll d_max = 0;
    ll d_min = A + B - 1;
    rep(i, N) {
        chmax(d_max, D[i] % (A + B));
        chmin(d_min, D[i] % (A + B));
    }
    if (d_max - d_min + 1 <= A) {
        cout << "Yes" << endl;
        return 0;
    }
    ll cnt = 1;
    while (clock() - start < 1.9 * CLOCKS_PER_SEC) {
        d_max = 0;
        d_min = A + B - 1;
        rep(i, N) {
            chmax(d_max, (D[i] + cnt) % (A + B));
            chmin(d_min, (D[i] + cnt) % (A + B));
        }
        if (d_max - d_min + 1 <= A) {
            cout << "Yes" << endl;
            return 0;
        }
        cnt++;
    }
    cout << "No" << endl;
}
