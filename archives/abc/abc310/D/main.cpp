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
    ll N, T, M;
    cin >> N >> T >> M;
    map<ll, set<ll>> not_friends;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        not_friends[a].insert(b);
        not_friends[b].insert(a);
    }
    vector<set<ll>> groups(T);
    set<vector<set<ll>>> ans_set;
    function<void(int)> solve = [&](int i) {
        if (i == N) {
            for (auto &g : groups) {
                if (g.empty()) return;
            }
            vector<set<ll>> tmp = groups;
            sort(all(tmp));
            ans_set.insert(tmp);
            return;
        }
        bool f = false;
        rep(t, T) {
            auto &g = groups[t];
            if (g.empty()) {
                if (f) break;
                f = true;
            }
            bool ok = true;
            for (auto &j : g) {
                if (not_friends[i].count(j)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                g.insert(i);
                solve(i + 1);
                g.erase(i);
            }
        }
    };
    if (T == 1) {
        groups[0].insert(0);
        solve(1);
    } else if (N >= 2) {
        groups[0].insert(0);
        groups[1].insert(1);
        solve(2);
        if (!not_friends[0].count(1)) {
            groups[0].clear();
            groups[1].clear();
            groups[0].insert(0);
            groups[0].insert(1);
            solve(2);
        }
    }
    cout << ans_set.size() << endl;
}
