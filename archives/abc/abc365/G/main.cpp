#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct TimeRange {
    int start;
    int end;
    TimeRange(int start) : start(start), end(-1) {}
};

int main() {
    cout << fixed << setprecision(18);
    int N, M;
    cin >> N >> M;
    vector<vector<TimeRange>> v(N);
    while (M--) {
        int t, p;
        cin >> t >> p;
        p--;
        if (v[p].empty() || v[p].back().end != -1) {
            v[p].emplace_back(t);
        } else {
            v[p].back().end = t;
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (v[a].empty() || v[b].empty()) {
            cout << 0 << endl;
            continue;
        }
        vl at(1e9 + 1, 0);
        int idx = 0;
        rep(i, 1, 1e9 + 1) {
            at[i] = at[i - 1];
            if (idx < v[a].size() && v[a][idx].start <= i && i <= v[a][idx].end) {
                at[i]++;
            }
        }
        ll ans = 0;
        for(auto& tr : v[b]) {
            if (tr.end == -1) {
                ans += at[tr.start];
            } else {
                ans += at[tr.end] - at[tr.start - 1];
            }
        }

        cout << ans << endl;
    }
}
