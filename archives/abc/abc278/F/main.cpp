#include <string>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N;
vs S;
Graph g;
vb visited;

bool solve(int cur) {
    bool res = false;
    map<string, bool> skip;
    for (auto v : g[cur]) {
        if (visited[v]) continue;
        string s = to_string(S[v].front()) + S[v].back();
        if (skip[s]) continue;
        skip[s] = true;
        visited[v] = true;
        res |= !solve(v);
        visited[v] = false;
    }
    return res;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    S.resize(N);
    cin >> S;
    g.resize(N);
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (S[i][S[i].size() - 1] == S[j][0]) {
                g.add_edge(i, j);
            }
        }
    }
    visited.resize(N, false);
    bool res = false;
    rep(i, N) {
        visited[i] = true;
        res |= !solve(i);
        visited[i] = false;
    }
    cout << (res ? "First" : "Second") << endl;
}
