#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    string S;
    ll Q;
    cin >> S >> Q;
    ll N = S.size();
    map<ll, multiset<ll>> memo;
    while (Q--) {
        string T;
        cin >> T;
        ll M = T.size();
        mint hash = 0;
        rep(i, M) { hash = hash * 26 + T[i] - 'a'; }
        mint s = 0;
        rep(i, M) { s = s * 26 + S[i] - 'a'; }
        ll ans = 0;
        if (memo.count(M)) {
            cout << memo[M].count(hash.val()) << endl;
            continue;
        }
        mint m_pow = mint(26).pow(M);
        rep(i, N - M + 1) {
            memo[M].insert(s.val());
            if (s == hash) ++ans;
            if (i + M < N) {
                s = s * 26 + S[i + M] - 'a';
                s -= mint(S[i] - 'a') * m_pow;
            }
        }
        cout << ans << endl;
    }
}
