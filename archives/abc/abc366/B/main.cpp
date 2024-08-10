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
    ll N;
    cin >> N;
    vs S(N);
    cin >> S;
    ll s_max = 0;
    for (auto&& s : S) {
        s_max = max(s_max, (ll)s.size());
    }
    vector<string> T(s_max, string(N, '*'));
    rep(i, N) {
        rep(j, S[i].size()) { T[j][i] = S[i][j]; }
    }
    for (auto&& t : T) {
        while(t[0] == '*') {
            t.erase(t.begin());
        }
        reverse(all(t));
    }
    for (auto&& t : T) {
        cout << t << endl;
    }
}
