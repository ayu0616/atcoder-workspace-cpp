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

bool solve(int i, int j, int energy, vvb visited) {
    if (i == gh && j == gw) return true;
    visited[i][j] = true;
    chmax(energy, drugs[i][j]);
    if (energy <= 0) return false;
    rep(k, 4) {
        int ni = i + dy4[k];
        int nj = j + dx4[k];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
        if (A[ni][nj] == '#') continue;
        if (visited[ni][nj]) continue;
        if (solve(ni, nj, energy - 1, visited)) return true;
    }
    visited[i][j] = false;
    return false;
}

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

    bool ans = solve(sh, sw, 0, visited);
    cout << (ans ? "Yes" : "No") << endl;
}
