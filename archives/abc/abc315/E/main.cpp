#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Mapper {
    map<int, int> mp;
    map<int, int> rev_mp;

    int size() { return mp.size(); }

    int get(int x) {
        if (mp.count(x)) return mp[x];
        int s = mp.size();
        mp[x] = s;
        rev_mp[s] = x;
        return s;
    }

    int rev(int x) { return rev_mp[x]; }
};

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vvl P(N);
    Graph G(N);
    UnionFind<int> uf(N);
    rep(i, N) {
        ll c;
        cin >> c;
        P[i].resize(c);
        rep(j, c) {
            ll p;
            cin >> p;
            p--;
            P[i][j] = p;
            G.add_edge(i, p);
        }
    }
    {
        vb visited(N, false);
        deque<int> q;
        q.push_back(0);
        while(!q.empty()) {
            int i = q.front(); q.pop_front();
            if (visited[i]) continue;
            visited[i] = true;
            for (auto &j : G[i]) {
                q.push_back(j);
                uf.unite(i, j);
            }
        }
    }
    Mapper mp;
    rep(i, N) {
        if (uf.same(0, i)) {
            mp.get(i);
        }
    }
    Graph G2(mp.size());
    rep(i, N) {
        if (uf.same(0, i)) {
            for (auto &j : P[i]) {
                G2.add_edge(mp.get(j), mp.get(i));
            }
        }
    }
    auto topo = G2.topological_sort();
    vi ans;
    for (auto &i : topo) {
        int i_rev = mp.rev(i);
        if (i_rev == 0) break;
        ans.push_back(i_rev+1);
    }
    cout << ans << endl;
}
