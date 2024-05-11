#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N;
ll ans = 0;
vs S;

ll solve(vector<int> s, int depth) {
    vector<int> groups[26];
    for (int i : s) {
        if (S[i].size() <= depth) continue;
        groups[S[i][depth] - 'a'].push_back(i);
    }
    ll dp = 0;
    rep(i, 100) {
        if (groups[i].size() >= 2) {
            dp += solve(groups[i], depth + 1);
        }
    }
    ll cnt_s = s.size();
    if (cnt_s == 0) return dp;
    ll n = cnt_s * (cnt_s - 1) / 2 - dp;
    ans += n * depth;
    return dp + n;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    S.resize(N);
    cin >> S;
    vector<int> s(N);
    iota(all(s), 0);
    solve(s, 0);
    cout << ans << endl;
}
