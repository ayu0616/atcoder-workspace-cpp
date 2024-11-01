#include <vector>
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
    ll N, Q;
    cin >> N >> Q;
    UnionFind<int> uf(N);
    vector<set<int>> vec(N);
    rep(i, N) vec[i].insert(i);
    while (Q--) {
        int type;
        cin >> type;
        switch (type) {
            case 1: {
                int u, v;
                cin >> u >> v;
                --u, --v;
                int u_root = uf.root(u);
                int v_root = uf.root(v);
                uf.unite(u, v);
                int root = uf.root(u);
                if (root == u_root) {
                    int cnt = 0;
                    auto it = vec[v_root].rbegin();
                    while (cnt < 10 && it != vec[v_root].rend()) {
                        vec[root].insert(*it);
                        ++it;
                        ++cnt;
                    }
                } else {
                    int cnt = 0;
                    auto it = vec[u_root].rbegin();
                    while (cnt < 10 && it != vec[u_root].rend()) {
                        vec[root].insert(*it);
                        ++it;
                        ++cnt;
                    }
                }
                break;
            }
            case 2: {
                int v, k;
                cin >> v >> k;
                --v;
                int root = uf.root(v);
                set<int> &v_set = vec[root];
                const int size = v_set.size();
                if (size < k) {
                    cout << -1 << endl;
                    break;
                }
                cout << *next(v_set.rbegin(), k - 1) + 1 << endl;
                break;
            }
        }
    }
}
