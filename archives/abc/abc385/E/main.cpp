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
    vvi g(N);
    rep(i, N - 1) {
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    ll ans = 0;
    rep(v, N) {
        vl d;
        for (auto u : g[v]) {
            int deg = g[u].size();
            if (deg == 1) continue;
            d.push_back(deg - 1);
        }
        sort(all(d));
        reverse(all(d));
        rep(j, d.size()) { chmax(ans, d[j] * (j + 1) + (j + 1) + 1); }
    }
    cout << N - ans << endl;
}
