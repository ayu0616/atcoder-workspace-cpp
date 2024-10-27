#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl P(N);
    cin >> P;
    rep(i, N) P[i]--;

    vi used(N, 0), ans(N, 0);
    rep(i, N) {
        if (used[i]) continue;
        vi cycle;
        int cur = i;
        while (used[cur] == 0) {
            cycle.push_back(cur);
            used[cur] = 1;
            cur = P[cur];
        }
        int cycle_size = cycle.size();
        rep(j, cycle_size) { ans[cycle[j]] = cycle[(j + mod_pow(2, K, cycle_size)) % cycle_size] + 1; }
    }
    cout << ans << endl;
}
