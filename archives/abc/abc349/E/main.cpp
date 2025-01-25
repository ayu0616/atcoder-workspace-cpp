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
    vvl A(3, vl(3));
    cin >> A;

    vvi state(3, vi(3, -1));
    map<vvi, int> memo;

    auto is_full = [&]() {
        rep(i, 3) rep(j, 3) if (state[i][j] == -1) return false;
        return true;
    };

    auto get_winner = [&]() {
        rep(i, 3) {
            if (state[i][0] == state[i][1] && state[i][1] == state[i][2] && state[i][0] != -1) return state[i][0];
            if (state[0][i] == state[1][i] && state[1][i] == state[2][i] && state[0][i] != -1) return state[0][i];
        }
        if (state[0][0] == state[1][1] && state[1][1] == state[2][2] && state[0][0] != -1) return state[0][0];
        if (state[0][2] == state[1][1] && state[1][1] == state[2][0] && state[0][2] != -1) return state[0][2];

        if (is_full()) {
            int takahashi = 0, aoki = 0;
            rep(i, 3) rep(j, 3) {
                if (state[i][j] == 0)
                    takahashi += A[i][j];
                else
                    aoki += A[i][j];
            }
            return takahashi > aoki ? 0 : 1;
        }

        return -1;
    };

    auto solve = [&](auto &&f, int turn) -> int {
        if (memo.count(state)) return memo[state];
        int winner = get_winner();
        if (winner != -1) return memo[state] = winner;
        int cnt = 0;
        rep(i, 3) rep(j, 3) {
            if (state[i][j] == -1) {
                state[i][j] = turn;
                if (f(f, 1 - turn) == 1 - turn) {
                    cnt++;
                }
                state[i][j] = -1;
            }
        }
        return memo[state] = (cnt == 0 ? 1 - turn : turn);
    };
    cout << (solve(solve, 0) == 0 ? "Takahashi" : "Aoki") << endl;
}
