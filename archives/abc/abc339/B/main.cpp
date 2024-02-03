#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vs grid(H);
    rep(i, H) grid[i] = string(W, '.');
    int w = 3, cx = 0, cy = 0;
    rep(i, N) {
        if (grid[cx][cy] == '.') {
            grid[cx][cy] = '#';
            w += 1;
            w %= 4;
        } else {
            grid[cx][cy] = '.';
            w += 3;
            w %= 4;
        }
        cx += dx[w] + H;
        cy += dy[w] + W;
        cx %= H;
        cy %= W;
    }
    rep(i, H) cout << grid[i] << endl;
}
