#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/segtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct T {
    int min, max;
};

T op(T a, T b) { return {std::min(a.min, b.min), std::max(a.max, b.max)}; }

T e() { return {INT_MAX, INT_MIN}; }

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl P(N);
    cin >> P;
    rep(i, N) P[i]--;
    vi idx(N);
    rep(i, N) idx[P[i]] = i;
    atcoder::segtree<T, op, e> seg(N);
    rep(i, N) seg.set(i, {idx[i], idx[i]});
    int ans = INT_MAX;
    for (int i = K; i <= N; ++i) {
        chmin(ans, seg.prod(i - K, i).max - seg.prod(i - K, i).min);
    }
    cout << ans << endl;
}
