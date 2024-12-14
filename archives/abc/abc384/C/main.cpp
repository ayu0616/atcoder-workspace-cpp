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
    ll points[5] = {0, 1, 2, 3, 4};
    rep(i, 5) {
        cin >> points[i];
    }
    vector<pair<ll, string>> ans;
    for (ll S = 1; S < 1 << 5; S++) {
        ll score = 0;
        string name = "";
        for(int i = 0; i < 5; i++) {
            if (S >> i & 1) {
                score += points[i];
                name += ('A' + i);
            }
        }
        ans.emplace_back(-score, name);
    }
    sort(all(ans));
    for(auto [score, name] : ans) {
        cout << name  << endl;
    }
}
