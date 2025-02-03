#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int N;

struct Info {
    int cost;
    int row;
    int col;
    char direction;

    bool operator<(const Info& rhs) const { return cost < rhs.cost; }
};

struct Operation {
    int pos;
    char direction;
};

map<vs, int> memo;
int get_init_cost(const vs& C) {
    if (memo.find(C) != memo.end()) {
        return memo[C];
    }
    map<pair<int, int>, int> cost;
    rep(i, N) rep(j, N) {
        if (C[i][j] == 'x') {
            cost[{i, j}] = N * N;
        }
    }
    for (int row = 0; row < N; row++) {
        int cnt = 0;
        for (int col = 0; col < N; col++) {
            if (C[row][col] == 'o') {
                cnt=1;
            }
            if (C[row][col] == 'x') {
                chmin(cost[{row, col}], (int)sqrt(100 * (col + 1 + cnt)) + N);
            }
        }
        for (int col = N - 1; col >= 0; col--) {
            int cnt = 0;
            if (C[row][col] == 'o') {
                cnt=1;
            }
            if (C[row][col] == 'x') {
                chmin(cost[{row, col}], (int)sqrt(100 * (N - col + cnt)) + N);
            }
        }
    }
    for (int col = 0; col < N; col++) {
        for (int row = 0; row < N; row++) {
            int cnt = 0;
            if (C[row][col] == 'o') {
                cnt=1;
            }
            if (C[row][col] == 'x') {
                chmin(cost[{row, col}], (int)sqrt(100 * (row + 1 + cnt)) + N);
            }
        }
        for (int row = N - 1; row >= 0; row--) {
            int cnt = 0;
            if (C[row][col] == 'o') {
                cnt=1;
            }
            if (C[row][col] == 'x') {
                chmin(cost[{row, col}], (int)sqrt(100 * (N - row + cnt)) + N);
            }
        }
    }
    int res = 0;
    for (auto& p : cost) {
        res += p.second;
    }
    return memo[C] = res;
}

// int get_next_cost(const vs& C, Operation op) {

// }

vs get_next_state(const vs& C, Operation op) {
    vs next_C = C;
    int pos = op.pos;
    char direction = op.direction;
    if (direction == 'L') {
        for (int c = 0; c < N - 1; ++c) {
            next_C[pos][c] = C[pos][c + 1];
        }
        next_C[pos][N - 1] = '.';
    } else if (direction == 'R') {
        for (int c = N - 1; c > 0; --c) {
            next_C[pos][c] = C[pos][c - 1];
        }
        next_C[pos][0] = '.';
    } else if (direction == 'U') {
        for (int r = 0; r < N - 1; ++r) {
            next_C[r][pos] = C[r + 1][pos];
        }
        next_C[N - 1][pos] = '.';
    } else if (direction == 'D') {
        for (int r = N - 1; r > 0; --r) {
            next_C[r][pos] = C[r - 1][pos];
        }
        next_C[0][pos] = '.';
    }
    return next_C;
}

void print_ans(vector<Operation>& ans) {
    for (const auto& op : ans) {
        cout << op.direction << " " << op.pos << endl;
    }
}

struct State {
    vs C;
    vector<Operation> ans;
    int cost;

    bool operator<(const State& rhs) const {
        if (cost != rhs.cost) {
            return cost < rhs.cost;
        } else {
            return rand() % 2 == 0;
        }
    }
    bool operator>(const State& rhs) const {
        if (cost != rhs.cost) {
            return cost > rhs.cost;
        } else {
            return rand() % 2 != 0;
        }
    }
};

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    vs C(N);
    cin >> C;
    priority_queue<State, vector<State>, greater<State>> pq;
    int cost_memo = get_init_cost(C);
    int same_cost_count = 0;
    pq.push({C, {}, cost_memo});
    while (pq.top().cost > 0) {
        State state = pq.top();
        if (state.cost == cost_memo) {
            same_cost_count++;
            if (same_cost_count >= 100) {
                break;
            }
        } else {
            same_cost_count = 0;
            cost_memo = state.cost;
        }
        if (state.ans.size() >= 4 * N * N) {
            break;
        }
        pq.pop();
        for (int pos = 0; pos < N; ++pos) {
            for (char direction : {'L', 'R', 'U', 'D'}) {
                if (direction == 'L' && state.C[pos][0] == 'o') continue;
                if (direction == 'R' && state.C[pos][N - 1] == 'o') continue;
                if (direction == 'U' && state.C[0][pos] == 'o') continue;
                if (direction == 'D' && state.C[N - 1][pos] == 'o') continue;
                vs next_C = get_next_state(state.C, {pos, direction});
                int next_cost = get_init_cost(next_C);
                State next_state = {next_C, state.ans, next_cost};
                next_state.ans.push_back({pos, direction});
                pq.push(next_state);
            }
        }
        constexpr int beam_width = 3000;
        priority_queue<State, vector<State>, greater<State>> next_pq;
        for (int i = 0; i < beam_width; ++i) {
            if (pq.empty()) break;
            State state = pq.top();
            pq.pop();
            next_pq.push(state);
        }
        pq = next_pq;
    }
    vector<Operation> ans = pq.top().ans;
    print_ans(ans);
}
