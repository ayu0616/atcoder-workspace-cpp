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
    ll H, W;
    cin >> H >> W;
    vs S(H);
    cin >> S;
    ll sx = 0, sy = 0;
    ll gx = 0, gy = 0;
    rep(i, 0, H) {
        rep(j, 0, W) {
            if (S[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (S[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    vector dist(H, vector(W, vector(2, LL_INF)));
    dist[sx][sy][0] = 0;
    dist[sx][sy][1] = 0;
    queue<tuple<ll, ll, ll>> q;
    q.push({sx, sy, 0});
    q.push({sx, sy, 1});
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        rep(i, 0, 4) {
            if (z == 0 && i % 2 == 0) continue;
            if (z == 1 && i % 2 == 1) continue;
            ll nx = x + dx4[i];
            ll ny = y + dy4[i];
            ll nz = 1 - z;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (S[nx][ny] == '#') continue;
            if (dist[nx][ny][nz] > dist[x][y][z] + 1) {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
    ll ans = min(dist[gx][gy][0], dist[gx][gy][1]);
    if (ans == LL_INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
