#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vvl _cnt(1000, vl(1000, -1));
ll cnt(vs &grid, int i, int j) {
    int N = grid.size();
    if (i < 0 || N <= i || j < 0 || N <= j) return 0;
    if (_cnt[i][j] != -1) return _cnt[i][j];
    if (0 < i && _cnt[i - 1][j] != -1) {
        _cnt[i][j] = _cnt[i - 1][j];
        rep(k, j + 1) _cnt[i][j] += grid[i][k] == 'B';
        return _cnt[i][j];
    }
    if (0 < j && _cnt[i][j - 1] != -1) {
        _cnt[i][j] = _cnt[i][j - 1];
        rep(k, i + 1) _cnt[i][j] += grid[k][j] == 'B';
        return _cnt[i][j];
    }
    if (i == 0 && j == 0) {
        _cnt[i][j] = grid[i][j] == 'B';
        return _cnt[i][j];
    }
    _cnt[i][j] = cnt(grid, i - 1, j) + cnt(grid, i, j - 1) - cnt(grid, i - 1, j - 1) + (grid[i][j] == 'B');
    return _cnt[i][j];
}

ll cnt(vs &grid, int i, int j, int k, int l) {
    int N = grid.size();
    int ans = cnt(grid, k, l);
    if (0 < i) ans -= cnt(grid, i - 1, l);
    if (0 < j) ans -= cnt(grid, k, j - 1);
    if (0 < i && 0 < j) ans += cnt(grid, i - 1, j - 1);
    return ans;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vs P(N);
    cin >> P;
    vs grid(2 * N);
    rep(i, N) {
        grid[i] = P[i] + P[i];
        grid[i + N] = P[i] + P[i];
    }
    while (Q--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        ll ans = 0;
        int a_n = A / N, b_n = B / N, c_n = C / N, d_n = D / N;
        int a_mod = A % N, b_mod = B % N, c_mod = C % N, d_mod = D % N;
        ll c1 = cnt(grid, a_mod, b_mod, c_mod + N * (a_mod >= c_mod), d_mod + N * (b_mod >= d_mod));
        ll c2 = cnt(grid, 0, B % N, N - 1, N - 1) * max(0, c_n - a_n - 1);
        ll c4 = cnt(grid, 0, 0, C % N, N - 1) * max(0, d_n - b_n - 1);
        ll c6 = cnt(grid, 0, 0, 0, D % N) * max(0, c_n - a_n - 1);
        ll c8 = cnt(grid, A % N, 0, C % N, D % N) * max(0, d_n - b_n - 1);
        ll c9 = cnt(grid, 0, 0, N - 1, N - 1) * max(0, c_n - a_n - 1) * max(0, d_n - b_n - 1);
        ans = c1 + c2 + c4 + c6 + c8 + c9;
        cout << ans << endl;
    }
}
