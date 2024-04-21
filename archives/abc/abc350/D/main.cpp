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
    ll N, M;
    cin >> N >> M;
    vl A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    UnionFind<ll> uf(N + 1);
    map<ll, ll> cnt;
    rep(i, M) {
        ll a = A[i], b = B[i];
        uf.unite(a, b);
    }
    rep(i, M) {
        ll a = A[i];
        cnt[uf.root(a)]++;
    }
    ll ans = 0;
    rep(i, N + 1) {
        if (uf.root(i) == i) {
            ll siz = uf.size(i);
            ans += siz * (siz - 1) / 2 - cnt[i];
        }
    }
    cout << ans << endl;
}
