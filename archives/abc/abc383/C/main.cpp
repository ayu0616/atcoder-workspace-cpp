#include <cassert>
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
    ll H, W, D;
    cin >> H >> W >> D;
    vs S(H);
    cin >> S;

    vector<vector<ll>> dist(H, vector<ll>(W, -1));

    rep(i, H) rep(j, W) {
        if (S[i][j] != 'H') continue;
        assert(S[i][j] == 'H');
        queue<tuple<ll, ll, ll>> q;
        q.push({i, j, D});
        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            assert(S[x][y] != '#');
            if (S[x][y] == 'H') {
                d = D;
            }
            if (dist[x][y] >= d) continue;
            dist[x][y] = d;
            if (d == 0) continue;
            if (x > 0 && S[x - 1][y] != '#') q.push({x - 1, y, d - 1});
            if (x < H - 1 && S[x + 1][y] != '#') q.push({x + 1, y, d - 1});
            if (y > 0 && S[x][y - 1] != '#') q.push({x, y - 1, d - 1});
            if (y < W - 1 && S[x][y + 1] != '#') q.push({x, y + 1, d - 1});
        }
    }

    ll ans = 0;
    rep(i, H) rep(j, W) {
        if (dist[i][j] >= 0) ans++;
    }

    cout << ans << endl;
}
