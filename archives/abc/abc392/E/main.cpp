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

struct E {
    int id, from, to;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vector<E> edges(M);
    vector<vector<E>> G(N);
    hassaku::UnionFind<> uf(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back({(int)i, a, b});
        G[b].push_back({(int)i, b, a});
        edges[i] = {(int)i, a, b};
        uf.unite(a, b);
    }
    vb used(M), visited(N);
    rep(g, N) {
        if (uf.root(g) != g) continue;
        queue<int> q;
        q.push(g);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            visited[v] = true;
            for (auto e : G[v]) {
                if (used[e.id]||visited[e.to]) continue;
                used[e.id] = true;
                visited[e.to] = true;
                if (e.from == v) {
                    q.push(e.to);
                } else {
                    q.push(e.from);
                }
            }
        }
    }
    vector<vector<int>> unused(N);
    rep(i, M) {
        if (!used[i]) {
            auto e = edges[i];
            int r = uf.root(e.from);
            unused[r].push_back(i);
        }
    }
    vector<int> roots;
    rep(i, N) {
        if (uf.root(i) == i) {
            roots.push_back(i);
        }
    }
    if (roots.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    sort(all(roots), [&](int a, int b) { return unused[a].size() > unused[b].size(); });
    vector<tuple<int, int, int>> ans;
    int l = 0, r = 1;
    while (r < roots.size()) {
        int a = roots[l];
        int b = roots[r];
        if (unused[a].size() == 0) {
            l++;
            continue;
        }
        int eid = unused[a].back();
        unused[a].pop_back();
        auto e = edges[eid];
        ans.push_back({eid + 1, e.from + 1, b + 1});
        r++;
    }
    cout << ans.size() << endl;
    for (auto [a, b, c] : ans) {
        cout << a << " " << b << " " << c << endl;
    }
}
