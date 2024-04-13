#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;
int N, H, W, gh, gw;
vs A;
vvi drugs;

int main() {
    cout << fixed << setprecision(18);
    cin >> H >> W;
    A.resize(H);
    cin >> A;
    cin >> N;
    drugs.resize(H, vi(W, 0));
    rep(i, N) {
        int r, c, e;
        cin >> r >> c >> e;
        r--, c--;
        drugs[r][c] = e;
    }
    vvb visited(H, vb(W, false));

    int sh, sw;
    rep(i, H) rep(j, W) {
        if (A[i][j] == 'S') {
            sh = i;
            sw = j;
        }
        if (A[i][j] == 'T') {
            gh = i;
            gw = j;
        }
    }

    // vvi d(H, vi(W, INT_INF));
    // d[gh][gw] = 0;
    // queue<pii> q;
    // q.push({gh, gw});
    // while (!q.empty()) {
    //     auto [i, j] = q.front();
    //     q.pop();
    //     rep(k, 4) {
    //         int ni = i + dy4[k];
    //         int nj = j + dx4[k];
    //         if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
    //         if (A[ni][nj] == '#') continue;
    //         if (d[ni][nj] != INT_INF) continue;
    //         d[ni][nj] = d[i][j] + 1;
    //         q.push({ni, nj});
    //     }
    // }

    vvi max_e(H, vi(W, 0));

    priority_queue<pair<int, pii>> pq;
    pq.push({drugs[sh][sw], {sh, sw}});
    while (!pq.empty()) {
        auto [energy, pos] = pq.top();
        pq.pop();
        auto [i, j] = pos;
        if (i == gh && j == gw) {
            cout << "Yes" << endl;
            return 0;
        }
        if (energy <= 0) continue;
        bool updated = false;
        if (max_e[i][j] < energy) {
            max_e[i][j] = energy;
            updated = true;
        }
        if (!updated) continue;
        rep(k, 4) {
            int ni = i + dy4[k];
            int nj = j + dx4[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (A[ni][nj] == '#') continue;
            if (visited[ni][nj]) continue;
            if (energy <= 0) continue;
            int ne = max(energy - 1, drugs[ni][nj]);
            pq.push({ne, {ni, nj}});
        }
    }
    cout << "No" << endl;

    // cout << (ans ? "Yes" : "No") << endl;
}
