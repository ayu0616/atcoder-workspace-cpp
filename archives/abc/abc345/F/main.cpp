#include <functional>
#include <queue>
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
    int N, M, K;
    cin >> N >> M >> K;
    if (K % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    UnionFind uf(N);
    vpii edges(M);
    vector<set<int>> node_to_edge(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
        edges[i] = {a, b};
        node_to_edge[a].insert(i);
        node_to_edge[b].insert(i);
    }
    vb lamp(N, false);
    vb used(N, false);
    vi ans;
    int count = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    rep(i, N) pq.push({node_to_edge[i].size(), i});
    while (!pq.empty()) {
        auto [size, i] = pq.top();
        pq.pop();
        if (size > 1) break;
        used[i] = true;
        int edge = *node_to_edge[i].begin();
        int a = edges[edge].first;
        int b = edges[edge].second;
        lamp[a] = !lamp[a];
        lamp[b] = !lamp[b];
        int c = 0;
        if (lamp[a])
            c++;
        else
            c--;
        if (lamp[b])
            c++;
        else
            c--;
        count += c;
        node_to_edge[a].erase(edge);
        node_to_edge[b].erase(edge);
        if (node_to_edge[a].size() == 1) pq.push({node_to_edge[a].size(), a});
        if (node_to_edge[b].size() == 1) pq.push({node_to_edge[b].size(), b});
        ans.push_back(edge + 1);
        if (count == K) {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            cout << ans << endl;
        }
    }
}
