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
    ll N, M;
    cin >> N >> M;
    vl A(N);
    cin >> A;
    vvi G(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vi score(N);
    score[0] = 1;
    priority_queue<pii, vpii, greater<pii>> q;
    q.push({A[0], 0});
    while (!q.empty()) {
        auto [a, v] = q.top();
        q.pop();
        for (auto u : G[v]) {
            if (A[u] < a) continue;
            int new_score = score[v];
            if (A[u] > a) new_score++;
            if (new_score > score[u]) {
                score[u] = new_score;
                q.push({A[u], u});
            }
        }
    }
    cout << score[N - 1] << endl;
}
