#include <cassert>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/segtree>

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

ll N, K;
vl A_sum;

ll get_range_sum(int l, int r) { return A_sum[r] - A_sum[l]; }

map<pii, mint> memo;
mint solve(int l, int r) {
    if (l == r) return memo[{l, r}] = 1;
    if (r - l == 1) return memo[{l, r}] = (get_range_sum(l, r) != K);
    if (memo.count({l, r})) return memo[{l, r}];
    mint res = (get_range_sum(l, r) != K);
    for (int i = l + 1; i < r; i++) {
        res += solve(l, i) * solve(i, r);
    }
    assert(res.val() <= pow(2, r - l - 1));
    return memo[{l, r}] = res;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> K;
    vl A(N);
    cin >> A;
    A_sum = vl(N + 1);
    rep(i, N) { A_sum[i + 1] = A_sum[i] + A[i]; }
    mint ans = solve(0, N);
    cout << ans << endl;
}
