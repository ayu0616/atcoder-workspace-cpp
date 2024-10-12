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
    string S;
    cin >> S;
    ll ans = 0;
    map<string, ll> mp1, mp2;
    rep(i, S.size()) {
        char c = S[i];
        for (char d = 'A'; d <= 'Z'; d++) {
            string s = to_string(c) + to_string(d);
            ans += mp2[s];
        }
        for (char d = 'A'; d <= 'Z'; d++) {
            string s = to_string(d) + to_string(c);
            mp2[s] += mp1[to_string(d)];
        }
        mp1[to_string(c)]++;
    }
    cout << ans << endl;
}
