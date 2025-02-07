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
    ll N;
    cin >> N;
    vl x(N), y(N), P(N);
    rep(i, N) cin >> x[i] >> y[i] >> P[i];
    function<bool(ll)> is_ok = [&](ll m) -> bool {
        vvi g(N);
        rep(i, N) rep(j, N) {
            if (i == j) continue;
            ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if (P[i] * m >= d) {
                g[i].push_back(j);
            }
        }
        rep(i, N) {
            vb visited(N);
            queue<ll> q;
            q.push(i);
            while (!q.empty()) {
                ll v = q.front();
                q.pop();
                visited[v] = true;
                for (ll u : g[v]) {
                    if (!visited[u]) {
                        q.push(u);
                    }
                }
            }
            bool ok = true;
            rep(j, N) {
                if (!visited[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    };
    cout << hassaku::binary_search((ll)1e10, 0ll, is_ok) << endl;
}
