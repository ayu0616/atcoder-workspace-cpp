#include <cassert>
#include <iostream>
#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N;
string S, T;
map<string, ll> mp;

void solve() {
    queue<pair<string, ll>> q;
    q.push({S+"..", 0});
    while (!q.empty()) {
        auto [s, cnt] = q.front();
        q.pop();
        // if (cnt > 10) {
        //     break;
        // }
        if (mp.count(s)) {
            continue;
        }
        mp[s] = cnt;
        int emp_idx = -1;
        rep(i, N + 1) {
            if (s[i] == '.') {
                emp_idx = i;
                break;
            }
        }
        assert(emp_idx != -1);
        rep(i, N + 1) {
            if (s[i] != '.' && s[i + 1] != '.') {
                string t = s;
                swap(t[i], t[emp_idx]);
                swap(t[i + 1], t[emp_idx + 1]);
                q.push({t, cnt + 1});
            }
        }
    }
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> S >> T;
    solve();
    if (mp.count(T + "..")) {
        cout << mp[T + ".."] << endl;
    } else {
        cout << -1 << endl;
    }
}
