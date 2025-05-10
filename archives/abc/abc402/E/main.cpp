#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Question {
    ll s, c, p;
    double e, cost_performance;
    Question(ll s, ll c, ll p) : s(s), c(c), p(p) {
        e = ((double)p / 100.0 * (double)s);
        cost_performance = (double)p / (double)c;
    }
    Question() : s(0), c(0), p(0) {}
};

int main() {
    cout << fixed << setprecision(18);
    ll N, X;
    cin >> N >> X;
    vl S(N), C(N), P(N);
    vector<Question> tasks(N);
    rep(i, N) {
        cin >> S[i] >> C[i] >> P[i];
        tasks[i] = Question(S[i], C[i], P[i]);
    }
    sort(all(tasks), [](Question a, Question b) { return a.cost_performance > b.cost_performance; });

    auto dfs = [&](auto &&dfs, int i, ll x, double cur) -> ll {
        if (i == N) {
            return cur;
        }
        // int c = 0;
        // for (auto i : res) {
        //     if (x < tasks[i].c) {
        //         c++;
        //     }
        // }
        // if (c == res.size()) {
        //     return cur;
        // }
        if (x < tasks[i].c) {
            return dfs(dfs, i + 1, x, cur);
        }
        double ans = 0;
        ans += dfs(dfs, i + 1, x - tasks[i].c, cur + tasks[i].s) * (tasks[i].p / 100.0);
        ans += dfs(dfs, i, x - tasks[i].c, cur) * ((100 - tasks[i].p) / 100.0);

        // double ans = 0;
        // for (auto i : res) {
        //     if (x < tasks[i].c) {
        //         continue;
        //     }
        //     double a = 0;
        //     set<int> tmp = res;
        //     a += dfs(dfs, tmp, x - tasks[i].c, cur) * ((100.0 - (double)tasks[i].p) / 100.0);
        //     tmp.erase(i);
        //     a += dfs(dfs, tmp, x - tasks[i].c, cur + tasks[i].s) * ((double)tasks[i].p / 100.0);
        //     ans = max(ans, a);
        // }
        return ans;
    };
    set<int> res;
    for (int i = 0; i < N; i++) {
        res.insert(i);
    }
    double ans = dfs(dfs, 0, X, 0);
    cout << ans << endl;
}
