#include <vector>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;
int N;
vl A;
map<ll, bool> memo;
int ans = 0;

void solve(vector<vector<int>> &s, int i) {
    // cnt++;
    if (i == N) {
        ll sum = 0;
        for (auto &group : s) {
            ll tmp = 0;
            for (auto &j : group) {
                tmp += A[j];
            }
            sum ^= tmp;
        }
        if (!memo[sum]) {
            ans++;
            memo[sum] = true;
        }
        return;
    }
    for (int j = 0; j < s.size(); j++) {
        s[j].push_back(i);
        solve(s, i + 1);
        s[j].pop_back();
    }
    s.push_back({i});
    solve(s, i + 1);
    s.pop_back();
};

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    A.resize(N);
    cin >> A;

    // map<pair<ll, vi>, bool> mp;

    // map<ll, ll> acc;
    // rep(S, 1LL << N) {
    //     ll sum = 0;
    //     rep(i, N) {
    //         if (S >> i & 1) {
    //             sum += A[i];
    //         }
    //     }
    //     acc[S] = sum;
    // }

    // ll cnt = 0;

    vector<vector<int>> s;
    solve(s, 0);

    // debug(cnt);

    cout << ans << endl;
}
