#include <functional>
#include <queue>
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
    ll N, K;
    cin >> N >> K;
    vl P(N);
    cin >> P;
    rep(i, N) P[i]--;
    vl ans(N, -1);
    set<int> s;
    hassaku::UnionFind<> uf(N);
    rep(i, N) {
        if (s.size() > 0) {
            auto it = s.lower_bound(P[i]);
            if (it != s.end()) {
                ll c = *it;
                uf.unite(c, P[i]);
                s.erase(it);
            }
        }
        s.insert(P[i]);
        if (uf.size(P[i]) >= K) {
            ans[uf.root(P[i])] = i + 1;
            s.erase(P[i]);
        }
    }

    rep(i, N) {
        ans[i] = ans[uf.root(i)];
        assert(uf.size(i) <= K);
    }

    for (int c : ans) {
        cout << c << endl;
    }
}
