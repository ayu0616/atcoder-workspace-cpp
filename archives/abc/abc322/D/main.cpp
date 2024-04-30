#include <algorithm>

#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr int GRID_SIZE = 8;

bool judge(vvi &grid) {
    rep(i, GRID_SIZE - 3) {
        rep(j, GRID_SIZE - 3) {
            if (grid[i][j] == 1) {
                bool ok = true;
                rep(k, 4) rep(l, 4) {
                    if (grid[i + k][j + l] != 1) {
                        ok = false;
                    }
                }
                return ok;
            }
        }
    }
    return false;
}

vvi rotate(vvi p, int r) {
    if (r == 0) return p;
    auto q = p;
    if (r == 1) {
        rep(i, 4) rep(j, 4) { p[i][j] = q[3 - j][i]; }
    } else if (r == 2) {
        rep(i, 4) rep(j, 4) { p[i][j] = q[3 - i][3 - j]; }
    } else {
        rep(i, 4) rep(j, 4) { p[i][j] = q[j][3 - i]; }
    }
    return p;
}

int main() {
    vvi P1(4, vi(4)), P2(4, vi(4)), P3(4, vi(4));
    rep(i, 4) rep(j, 4) {
        char c;
        cin >> c;
        P1[i][j] = c == '#';
    }
    rep(i, 4) rep(j, 4) {
        char c;
        cin >> c;
        P2[i][j] = c == '#';
    }
    rep(i, 4) rep(j, 4) {
        char c;
        cin >> c;
        P3[i][j] = c == '#';
    }
    int p_cnt = 0;
    rep(i, 4) rep(j, 4) { p_cnt += P1[i][j] + P2[i][j] + P3[i][j]; }
    if (p_cnt != 16) {
        cout << "No" << endl;
        return 0;
    }
    vvi grid(GRID_SIZE, vi(GRID_SIZE));
    vector<vvi> P[] = {
        {P1, rotate(P1, 1), rotate(P1, 2), rotate(P1, 3)},
        {P2, rotate(P2, 1), rotate(P2, 2), rotate(P2, 3)},
        {P3, rotate(P3, 1), rotate(P3, 2), rotate(P3, 3)},
    };
    function<bool(int, vvi)> dfs = [&](int depth, vvi grid) {
        if (depth == 3) {
            return judge(grid);
        }
        rep(i, GRID_SIZE - 3) {
            rep(j, GRID_SIZE - 3) {
                rep(r, 4) {
                    auto p = P[depth][r];
                    bool ok = true;
                    rep(k, 4) rep(l, 4) {
                        if (grid[i + k][j + l] == 1 && p[k][l] == 1) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        vvi next_grid = grid;
                        rep(k, 4) rep(l, 4) {
                            if (p[k][l] == 1) {
                                next_grid[i + k][j + l] = 1;
                            }
                        }
                        if (dfs(depth + 1, next_grid)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    };
    if (dfs(0, grid)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
