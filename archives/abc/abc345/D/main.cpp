#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool solve(int N, int H, int W, vi& A, vi& B, int h, int w, vb used, vvb grid) {
    rep(i, N) {
        if (used[i]) continue;
        bool ok = true;
        for (int y = h; y < h + A[i]; y++) {
            for (int x = w; x < w + B[i]; x++) {
                if (y < 0 || y >= H || x < 0 || x >= W || grid[y][x]) ok = false;
            }
        }
        if (!ok) continue;
        for (int y = h; y < h + A[i]; y++) {
            for (int x = w; x < w + B[i]; x++) {
                grid[y][x] = true;
            }
        }
        used[i] = true;
        rep(y, H) {
            bool ok = true;
            rep(x, W) {
                if (!grid[y][x]) {
                    if (solve(N, H, W, A, B, y, x, used, grid)) return true;
                    ok = false;
                    break;
                }
                if (y == H - 1 && x == W - 1 && grid[y][x]) {
                    return true;
                }
            }
            if (!ok) break;
        }
        for (int y = h; y < h + A[i]; y++) {
            for (int x = w; x < w + B[i]; x++) {
                grid[y][x] = false;
            }
        }
        used[i] = false;
    }
    rep(i, N) {
        if (used[i]) continue;
        bool ok = true;
        for (int y = h; y < h + B[i]; y++) {
            for (int x = w; x < w + A[i]; x++) {
                if (y < 0 || y >= H || x < 0 || x >= W || grid[y][x]) ok = false;
            }
        }
        if (!ok) continue;
        for (int y = h; y < h + B[i]; y++) {
            for (int x = w; x < w + A[i]; x++) {
                grid[y][x] = true;
            }
        }
        used[i] = true;
        rep(y, H) {
            bool ok = true;
            rep(x, W) {
                if (!grid[y][x]) {
                    if (solve(N, H, W, A, B, y, x, used, grid)) return true;
                    ok = false;
                    break;
                }
                if (y == H - 1 && x == W - 1 && grid[y][x]) {
                    return true;
                }
            }
            if (!ok) break;
        }
        for (int y = h; y < h + B[i]; y++) {
            for (int x = w; x < w + A[i]; x++) {
                grid[y][x] = false;
            }
        }
        used[i] = false;
    }
    return false;
}

int main() {
    cout << fixed << setprecision(18);
    int N, H, W;
    cin >> N >> H >> W;
    vi A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    vb used(N, false);
    vvb grid(H, vb(W, false));

    bool ans = solve(N, H, W, A, B, 0, 0, used, grid);

    cout << (ans ? "Yes" : "No") << endl;
}
