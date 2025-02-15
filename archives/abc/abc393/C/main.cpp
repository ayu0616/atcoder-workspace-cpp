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
    vector<pii> edges;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(min(u, v), max(u, v));
    }
    set<pii> es;
    ll ans = 0;
    rep(i, M) {
        pii edge = edges[i];
        auto [u, v] = edge;
        if (u == v) {
            ans++;
        } else {
            if (es.contains(edge)) {
                ans++;
            }
        }
        es.insert(edges[i]);
    }
    cout << ans << endl;
}
