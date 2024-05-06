#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vi A(N);
    cin >> A;
    rep(i, N) A[i]--;
    Graph g(N), g_rev(N);
    int ans = 0;
    rep(i, N) {
        g.add_edge(i, A[i]);
        g_rev.add_edge(A[i], i);
        if (i == A[i]) ans++;
    }
    auto scc = g.scc(g_rev);
    rep(i, N) {
        if (scc.is_root(i) && scc.size(i) >= 2) ans += scc.size(i);
    }
    cout << ans << endl;
}
