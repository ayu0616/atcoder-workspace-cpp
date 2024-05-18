#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vector<set<int>> G;
ll N;

struct State {
    vb removed;
    int turn;
};

map<vb, bool> memo;
bool dfs(State state) {
    if (memo.count(state.removed)) {
        return memo[state.removed];
    }
    bool goal = true;
    for (auto e : G) {
        for (int i : e) {
            if (!state.removed[i]) {
                goal = false;
                break;
            }
        }
    }
    if (goal) {
        return memo[state.removed] = false;
    }
    rep(i, N) {
        if (state.removed[i]) continue;
        for (int j : G[i]) {
            if (!state.removed[j]) {
                State next = state;
                next.removed[i] = true;
                next.removed[j] = true;
                next.turn++;
                if (!dfs(next)) {
                    return memo[state.removed] = true;
                }
            }
        }
    }
    return memo[state.removed] = false;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    vl A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    G.resize(N);
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (A[i] == A[j] || B[i] == B[j]) {
                G[i].insert(j);
            }
        }
    }
    State init = {vb(N, false), 0};
    if (dfs(init)) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
