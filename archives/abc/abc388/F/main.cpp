#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N, M, A, B;

bool judge(ll i) {
    if (i > 400) return true;
    if (i == 0) return true;
    if (i < A) return false;

    vector<bool> dp(i + 1, false);
    dp[0] = true;
    for (ll j = A; j <= i; ++j) {
        for (ll k = A; k <= B && k <= j; ++k) {
            if (dp[j - k]) {
                dp[j] = true;
                break;
            }
        }
    }
    return dp[i];
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> M >> A >> B;
    vl L(M), R(M);
    rep(i, M) {
        cin >> L[i] >> R[i];
        L[i]--;
    }
    vvl li(M);
    rep(i, M) {
        for (ll j = R[i] - B; j < L[i]; j++) {
            if (j < 0 || j >= N) continue;
            li[i].push_back(j);
        }
    }
    set<ll> s;
    s.insert(0);
    rep(i, M) {
        set<ll> t;
        ll r = R[i];
        for (auto si : s) {
            for (ll l : li[i]) {
                if (!judge(l - si)) continue;
                for (ll j = A; j <= B; j++) {
                    if (l + j < 0 || l + j >= N || l + j < r) continue;
                    t.insert(l + j);
                }
            }
        }
        s = t;
    }
    for (auto si : s) {
        if (judge(N - 1 - si)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
