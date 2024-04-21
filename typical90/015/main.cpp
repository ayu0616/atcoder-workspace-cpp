#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int _N;
mint N;
mint calc(int k, int n) {
    if (k == 0) return 0;
    if (k * 2 > n) {
        return k;
    }
    return calc(k, n - k) + k;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> _N;
    N = _N;
    vector<mint> cnt(_N), ans(_N, 0);
    rep(k, _N) { cnt[k] = calc(k, _N); }
    ans[0] = cnt[0] + N;
    rep(i, _N - 1) { ans[i + 1] = ans[i] + cnt[i + 1]; }
    reverse(all(ans));
    for (auto a : ans) cout << a << endl;
}
