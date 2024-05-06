#include <vector>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Security {
    int p, h;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, M, K;
    cin >> N >> M >> K;
    Graph g(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    vector<Security> sec(K);
    rep(i, K) {
        int p, h;
        cin >> p >> h;
        p--;
        sec[i] = {p, h};
    }

    vi score(N, -1);
    rep(i, K) {
        int p = sec[i].p, h = sec[i].h;
        score[p] = h;
    }
    sort(all(sec), [](const Security &a, const Security &b) { return a.h > b.h; });
    for (auto [p, h] : sec) {
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &e : g[u]) {
                int w = *e.to;
                if (score[w] < score[u] - 1) {
                    score[w] = score[u] - 1;
                    q.push(w);
                }
            }
        }
    }
    vi ans;
    rep(i, N) if (score[i] >= 0) ans.push_back(i + 1);
    cout << ans.size() << endl;
    cout << ans << endl;
}
