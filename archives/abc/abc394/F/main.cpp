#include <iostream>
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
    ll N;
    cin >> N;
    vvi G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vi score(N);
    rep(i, N) {
        for (auto j : G[i]) {
            score[i] += (G[j].size() >= 4) ? 1 : 0;
        }
    }
    rep(i, N) {
        sort(all(G[i]), [&](int a, int b) { return score[a] > score[b]; });
    }
    vb visited(N);
    int ans = -1;
    vi nodes(N);
    iota(all(nodes), 0);
    sort(all(nodes), [&](int a, int b) { return score[a] > score[b]; });
    for (auto i : nodes) {
        if (G[i].size() < 4 || visited[i]) {
            continue;
        }
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int cur = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            int cnt = 0;
            for (auto j : G[v]) {
                if (visited[j]) continue;
                cnt++;
                if (G[j].size() >= 4) {
                    q.push(j);
                    visited[j] = true;
                }
                if (i == v) {
                    if (cnt == 4) break;
                } else {
                    if (cnt == 3) break;
                }
            }
            cur += cnt;
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
