#include <iostream>

#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    rep(i, N) A[i]--;
    vvl v(N);
    rep(i, N) { v[A[i]].push_back(i); }
    vvl v_diff(N);
    rep(i, N) {
        if (v[i].size() == 0) continue;
        rep(j, v[i].size() - 1) { v_diff[i].push_back(v[i][j + 1] - v[i][j] - 1); }
    }
    rep(i, N) {
        rep(j, v_diff[i].size()) { v_diff[i][j] *= (v_diff[i].size() - j) * (j + 1); }
    }
    ll ans = 0;
    rep(i, N) {
        for (auto x : v_diff[i]) {
            ans += x;
        }
    }
    cout << ans << endl;
}
