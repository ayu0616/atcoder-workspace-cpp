#include <string>
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

bool inline is_kaibun(const string S) {
    string T = S;
    reverse(all(T));
    if (S == T)
        return true;
    else
        return false;
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vs C(N);
    cin >> C;
    vector<vvi> G(26, vvi(N));
    vector<vvi> Grev(26, vvi(N));
    rep(i, N) rep(j, N) {
        if (C[i][j] != '-') {
            G[C[i][j] - 'a'][i].push_back(j);
            Grev[C[i][j] - 'a'][j].push_back(i);
        }
    }
    vvi ans(N, vi(N, INT_INF));
    queue<pair<pair<int, int>, int>> q;
    rep(i, N) {
        q.push({{i, i}, 0});
        ans[i][i] = 0;
    }
    rep(i, N) {
        rep(c, 26) {
            for (auto j : G[c][i]) {
                q.push({{i, j}, 1});
                chmin(ans[i][j], 1);
            }
        }
    }

    while (!q.empty()) {
        auto [p, l] = q.front();
        q.pop();
        if (l > N + 5) break;
        auto [i, j] = p;
        rep(col, 26) {
            for (auto bi : Grev[col][i]) {
                for (auto aj : G[col][j]) {
                    if (C[bi][i] != '-' && C[bi][i] == C[j][aj]) {
                        chmin(ans[bi][aj], l + 2);
                        q.push({{bi, aj}, l + 2});
                    }
                }
            }
        }
    }

    rep(i, N) rep(j, N) {
        if (ans[i][j] == INT_INF) {
            ans[i][j] = -1;
        }
    }

    cout << ans << endl;
}
