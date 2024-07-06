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
    vl A(N - 1), B(N - 1), C(N - 1);
    rep(i, N - 1) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--, B[i]--;
    }
    Graph g(N);
    rep(i, N - 1) {
        g.add_edge(A[i], B[i], C[i]);
        g.add_edge(B[i], A[i], C[i]);
    }
    auto d = g.dyjkstra(0);
    int d_max_idx = -1;
    ll max_d = 0;
    rep(i, N) {
        if (chmax(max_d, d[i])) {
            d_max_idx = i;
        }
    }
    auto d2 = g.dyjkstra(d_max_idx);
    ll ans = 0;
    rep(i, N - 1) { ans += 2 * C[i]; }
    ans -= *max_element(all(d2));
    cout << ans << endl;
}
