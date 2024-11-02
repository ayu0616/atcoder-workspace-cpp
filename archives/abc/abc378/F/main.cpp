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
    Graph g(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    map<int, ll> mp;
    rep(i, N) { mp[g[i].size()]++; }
    ll ans = mp[3] * ((mp[2] * (mp[2] - 1)) / 2);
    cout << ans << endl;
}
