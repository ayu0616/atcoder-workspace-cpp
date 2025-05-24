#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll H, W;
    cin >> H >> W;
    vs S(H);
    cin >> S;

    vpii escapes;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == 'E') {
                escapes.push_back({i, j});
            }
        }
    }

    queue<tuple<int, int, int>> que;
    vvl dist(H, vl(W, -1));
    for (auto [i, j] : escapes) {
        que.push({i, j, 0});
        dist[i][j] = 0;
    }
    while (!que.empty()) {
        auto [i, j, d] = que.front();
        que.pop();
        rep(k, 4) {
            int ni = i + dy4[k];
            int nj = j + dx4[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (S[ni][nj] == '#') continue;
            if (dist[ni][nj] != -1) continue;
            dist[ni][nj] = d + 1;
            que.push({ni, nj, d + 1});
        }
    }
    auto T = S;
    rep(i, H) rep(j, W) {
        if (S[i][j] == '#') continue;
        if (S[i][j] == 'E') continue;
        rep(k, 4) {
            int ni = i + dy4[k];
            int nj = j + dx4[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (S[ni][nj] == '#') continue;
            if (dist[ni][nj] == dist[i][j] - 1) {
                if (k == 0) T[i][j] = '>';
                if (k == 1) T[i][j] = 'v';
                if (k == 2) T[i][j] = '<';
                if (k == 3) T[i][j] = '^';
                break;
            }
        }
    }
    for (auto t : T) {
        cout << t << endl;
    }
}
