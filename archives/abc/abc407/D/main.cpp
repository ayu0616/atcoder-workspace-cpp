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
    vvl A(H, vl(W));
    cin >> A;
    set<vvb> grids;
    grids.insert(vvb(H, vb(W, false)));
    rep(i, H) rep(j, W) {
        set<vvb> new_grids = grids;
        for (auto grid : grids) {
            if (grid[i][j]) {
                continue;
            }
            if (i < H - 1 && !grid[i + 1][j]) {
                vvb new_grid = grid;
                new_grid[i][j] = true;
                new_grid[i + 1][j] = true;
                new_grids.insert(new_grid);
            }
            if (j < W - 1 && !grid[i][j + 1]) {
                vvb new_grid = grid;
                new_grid[i][j] = true;
                new_grid[i][j + 1] = true;
                new_grids.insert(new_grid);
            }
        }
        grids = new_grids;
    }
    ll ans = 0;
    for (auto grid : grids) {
        ll score = 0;
        rep(i, H) rep(j, W) {
            if (!grid[i][j]) {
                score ^= A[i][j];
            }
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
}
