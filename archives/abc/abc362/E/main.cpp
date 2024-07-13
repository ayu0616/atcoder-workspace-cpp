#include <vector>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

map<ll, mint> fact_memo;
mint fact(ll n) {
    if (n == 0) return 1;
    if (fact_memo.count(n)) return fact_memo[n];
    return fact_memo[n] = fact(n - 1) * n;
}

mint comb(ll n, ll r) { return fact(n) / fact(r) / fact(n - r); }

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    map<ll, map<ll, map<ll, mint>>> dp;
    vector<mint> ans(N + 1, 0);
    ans[1] = N;
    rep(i, N) {
        auto a = A[i];
        rep(j, i) {
            auto b = A[j];
            auto d = a - b;
            dp[a + d][d][2] += 1;
            ans[2] += 1;
        }
        for (auto mp : dp[a]) {
            auto d = mp.first;
            for (auto [len, cnt] : mp.second) {
                mint c = cnt;
                if (d == 0) continue;
                dp[a + d][d][len + 1] += c;
                ans[len + 1] += c;
                // cerr << "a=" << a << " d=" << d << " len=" << len << " c=" << c << endl;
            }
        }
    }
    map<ll, ll> cnt;
    rep(i, N) { cnt[A[i]] += 1; }
    for (auto [a, c] : cnt) {
        if (c >= 3) {
            rep(i, 3, c + 1) { ans[i] += comb(c, i); }
        }
    }
    cout << vector<mint>(ans.begin() + 1, ans.end()) << endl;
}
