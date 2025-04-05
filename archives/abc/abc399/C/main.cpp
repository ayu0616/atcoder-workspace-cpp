#include "hassaku/union-find.hpp"
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }
    vvi g(N);
    hassaku::UnionFind<int> uf(N);
    int ans = 0;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (uf.same(u, v)) {
            ans++;
        }else{
            uf.unite(u, v);
        }
    }
    // int ans = 0;
    // rep(i, N) {
    //     if (uf.root(i) == i) {
    //         ans += uf.size(i) - 1;
    //     }
    // }
    cout<<ans<<endl;
    // cout << N - ans << endl;
}
