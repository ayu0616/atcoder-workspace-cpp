#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Edges {
    ll K, C;
    vl A;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    UnionFind<ll> uf(N);
    vector<Edges> edges(M);
    rep(i, M) {
        ll k, c;
        cin >> k >> c;
        edges[i].K = k;
        edges[i].C = c;
        rep(j, k) {
            ll a;
            cin >> a;
            a--;
            edges[i].A.push_back(a);
            if (j > 0) {
                uf.unite(edges[i].A[j - 1], edges[i].A[j]);
            }
        }
    }
    if (uf.size(0) != N) {
        cout << -1 << endl;
        return 0;
    }
    sort(all(edges), [](const Edges &lhs, const Edges &rhs) { return lhs.C < rhs.C; });
    UnionFind<ll> uf2(N);
    ll ans = 0;
    rep(i, M) {
        auto &e = edges[i];
        auto K = e.K;
        auto C = e.C;
        auto A = e.A;
        auto a = A[0];
        rep(i, 1, K) {
            auto b = A[i];
            if (uf2.same(a, b)) {
                continue;
            }
            uf2.unite(a, b);
            ans += C;
        }
        if (uf2.size(0) == N) {
            break;
        }
    }
    cout << ans << endl;
}
