#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll pw(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

ll solve(ll R) {
    if (R < 10) {
        return 0;
    }
    ll R_digits = 0;
    ll tmp = R;
    while (tmp) {
        R_digits++;
        tmp /= 10;
    }
    ll ans = 0;
    rep(i, 1, R_digits - 1) {
        rep(j, 1, 10) { ans += pw(j, i); }
    }
    ll R_top = R / pw(10, R_digits - 1);
    rep(j, 1, R_top) { ans += pw(j, R_digits - 1); }
    vector dp(R_digits, vector(2, 0LL));
    dp[0][1] = 1;
    bool ok = false;
    rep(i, 1, R_digits) {
        ll r = (R / pw(10, R_digits - i - 1)) % 10;
        if (ok || r >= R_top) {
            ok = true;
            dp[i][1] = 0;
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * R_top;
        } else {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = dp[i - 1][0] * R_top + dp[i - 1][1] * r;
        }
    }
    ans += dp[R_digits - 1][0] + dp[R_digits - 1][1];

    return ans;
}

int main() {
    cout << fixed << setprecision(18);
    ll L, R;
    cin >> L >> R;
    cout << solve(R) - solve(L - 1) << endl;
}
