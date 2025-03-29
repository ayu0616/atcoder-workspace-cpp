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
    ll N,M;
    cin >> N>>M;
    ll ans = 0;
    vvl graph(N, vl(N, 0));
    rep(M){
        ll u, v, w;
        cin>>u>>v>>w;
        u--;v--;
        graph[u][v] = w;
        graph[v][u] = w;
    }
}
