#include <functional>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool prefix_compare(const string &a, const string &b) {
    if (a.size() < b.size()) {
        return a < b.substr(0, a.size());
    } else {
        return a.substr(0, b.size()) < b;
    }
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vs S(N);
    cin >> S;
    sort(all(S));
    ll ans = 0;
    rep(i, N) {
        int ub = S.size(), lb = i + 1;
        string s = "";
        rep(j, S[i].size()) {
            s += S[i][j];
            ub = upper_bound(S.begin() + lb, S.begin() + ub, s, prefix_compare) - S.begin();
            lb = lower_bound(S.begin() + lb, S.begin() + ub, s, prefix_compare) - S.begin();
            ans += ub - lb;
            if (ub - lb == 0) break;
        }
    }
    cout << ans << endl;
}
