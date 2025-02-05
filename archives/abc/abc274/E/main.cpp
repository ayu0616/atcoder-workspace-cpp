#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vpll pos(N + M);
    rep(i, N + M) cin >> pos[i].first >> pos[i].second;
    reverse(all(pos));
    vector dp(1LL << (N + M), vector(N + M + 1, (double)LL_INF));
    rep(i, N + M) dp[1LL << i][i] = sqrt(pos[i].first * pos[i].first + pos[i].second * pos[i].second);
    for (ll S = 0; S < (1LL << (N + M)); S++) {
        double k = 1;
        rep(i, M) {
            if (S & (1LL << i)) k *= 0.5;
        }
        rep(next, N + M) {
            if (S & (1LL << next)) continue;
            rep(i, N + M) {
                if (S & (1LL << i)) {
                    chmin(dp[S | (1LL << next)][next], dp[S][i] + k * sqrt((pos[i].first - pos[next].first) * (pos[i].first - pos[next].first) +
                                                                           (pos[i].second - pos[next].second) * (pos[i].second - pos[next].second)));
                }
            }
        }
    }
    double ans = 1e18;
    for (ll S = (1LL << (N + M)) - (1LL << M); S < (1LL << (N + M)); S++) {
        double k = 1;
        rep(i, M) {
            if (S & (1LL << i)) k *= 0.5;
        }
        rep(i, N + M) {
            double dist = dp[S][i] +k* sqrt(pos[i].first * pos[i].first + pos[i].second * pos[i].second);
            chmin(ans, dist);
        }
    }
    cout << ans << endl;
}
