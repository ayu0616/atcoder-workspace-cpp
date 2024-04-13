#include <type_traits>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr char* TAKAHASHI = "Takahashi";
constexpr char* AOKI = "Aoki";
constexpr int TA = 1;
constexpr int AO = -1;
vvl A;

struct State {
    string turn;
    ll score;
    vvi grid = vvi(3, vi(3, 0));

    bool is_win() {
        rep(i, 3) {
            bool ok_row = true;
            bool ok_col = true;
            rep(j, 3) {
                if (grid[i][j] != TA) {
                    ok_row = false;
                }
                if (grid[j][i] != TA) {
                    ok_col = false;
                }
            }
            if (ok_row || ok_col) {
                score = LL_INF - 1;
                return true;
            }
        }
        if (grid[0][0] == TA && grid[1][1] == TA && grid[2][2] == TA) {
            score = LL_INF - 1;
            return true;
        }
        if (grid[0][2] == TA && grid[1][1] == TA && grid[2][0] == TA) {
            score = LL_INF - 1;
            return true;
        }
        if (is_end()) {
            return score > 0;
        }
        return false;
    }
    bool is_lose() {
        rep(i, 3) {
            bool ok_row = true;
            bool ok_col = true;
            rep(j, 3) {
                if (grid[i][j] != AO) {
                    ok_row = false;
                }
                if (grid[j][i] != AO) {
                    ok_col = false;
                }
            }
            if (ok_row || ok_col) {
                score = -LL_INF + 1;
                return true;
            }
        }
        if (grid[0][0] == AO && grid[1][1] == AO && grid[2][2] == AO) {
            score = -LL_INF + 1;
            return true;
        }
        if (grid[0][2] == AO && grid[1][1] == AO && grid[2][0] == AO) {
            score = -LL_INF + 1;
            return true;
        }
        if (is_end()) {
            return score < 0;
        }
        return false;
    }
    State next(ll i, ll j) {
        State next = *this;
        if (turn == TAKAHASHI) {
            next.grid[i][j] = TA;
            next.score += A[i][j];
            next.turn = AOKI;
        } else {
            next.grid[i][j] = AO;
            next.score -= A[i][j];
            next.turn = TAKAHASHI;
        }
        return next;
    }
    bool is_end() {
        rep(i, 3) rep(j, 3) {
            if (grid[i][j] == 0) {
                return false;
            }
        }
        return true;
    }
};

ll alpha_beta(State& s, ll alpha, ll beta) {
    if (s.is_lose() || s.is_win()) {
        ll sc = s.score;
        return sc;
    }
    rep(i, 3) rep(j, 3) {
        if (s.grid[i][j] != 0) continue;
        State next = s.next(i, j);
        ll score = -alpha_beta(next, -beta, -alpha);
        if (score > alpha) {
            alpha = score;
        }
        if (alpha >= beta) {
            return alpha;
        }
    }
    return alpha;
}

pll alpha_beta_action(State& s) {
    ll alpha = -LL_INF;
    pll best_action = {-1, -1};
    rep(i, 3) rep(j, 3) {
        if (s.grid[i][j] != 0) continue;
        State next = s.next(i, j);
        ll score = -alpha_beta(next, -LL_INF, -alpha);
        if (score > alpha) {
            best_action = {i, j};
            alpha = score;
        }
    }
    if (best_action.first == -1 && best_action.second == -1) {
        rep(i, 3) rep(j, 3) {
            if (s.grid[i][j] == 0) {
                best_action = {i, j};
                break;
            }
        }
    }
    return best_action;
}

int winner(vvi grid) {
    rep(i, 3) {
        bool ok_row = true;
        bool ok_col = true;
        rep(j, 3) {
            if (grid[i][j] != TA) {
                ok_row = false;
            }
            if (grid[j][i] != TA) {
                ok_col = false;
            }
        }
        if (ok_row || ok_col) {
            return TA;
        }
    }
    if (grid[0][0] == TA && grid[1][1] == TA && grid[2][2] == TA) {
        return TA;
    }
    if (grid[0][2] == TA && grid[1][1] == TA && grid[2][0] == TA) {
        return TA;
    }
    rep(i, 3) {
        bool ok_row = true;
        bool ok_col = true;
        rep(j, 3) {
            if (grid[i][j] != AO) {
                ok_row = false;
            }
            if (grid[j][i] != AO) {
                ok_col = false;
            }
        }
        if (ok_row || ok_col) {
            return AO;
        }
    }
    if (grid[0][0] == AO && grid[1][1] == AO && grid[2][2] == AO) {
        return AO;
    }
    if (grid[0][2] == AO && grid[1][1] == AO && grid[2][0] == AO) {
        return AO;
    }
    bool is_fill = true;
    ll score = 0;
    rep(i, 3) rep(j, 3) {
        if (grid[i][j] == 0) {
            is_fill = false;
        }
        if (grid[i][j] == TA) {
            score += A[i][j];
        } else if (grid[i][j] == AO) {
            score -= A[i][j];
        }
    }
    if (is_fill) {
        if (score > 0) {
            return TA;
        } else if (score < 0) {
            return AO;
        }
    }
    return 0;
}

int solve(vvi grid, int turn) {
    int win = winner(grid);
    if (win != 0) {
        return win;
    }
    rep(i, 3) rep(j, 3) {
        if (grid[i][j] != 0) continue;
        if (turn == TA) {
            grid[i][j] = TA;
        } else {
            grid[i][j] = AO;
        }
        int res = solve(grid, -turn);
        if (res == turn) {
            return turn;
        }
    }
    return -turn;
}

int main() {
    cout << fixed << setprecision(18);
    A.resize(3, vl(3));
    cin >> A;

    // State s = {TAKAHASHI, 0, vvi(3, vi(3, 0))};
    // while (!s.is_win() && !s.is_lose()) {
    //     auto [i, j] = alpha_beta_action(s);
    //     s = s.next(i, j);
    // }
    // rep(i, 3) rep(j, 3) {
    //     vvi g = vvi(3, vi(3, 0));
    //     g[i][j] = TA;
    //     debug(solve(g, AO));
    // }
    vvi gr = vvi(3, vi(3, 0));
    if (solve(gr, TA) == TA) {
        cout << TAKAHASHI << endl;
    } else {
        cout << AOKI << endl;
    }
}