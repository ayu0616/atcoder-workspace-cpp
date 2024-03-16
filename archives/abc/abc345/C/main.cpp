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
    map<char, ll> mp;
    for (char c : S) {
        mp[c]++;
    }
    bool ok = false;
    for (auto [k, v] : mp) {
        if (v >= 2) {
            ok = true;
            break;
        }
    }
    ll ans = ok ? 1 : 0;
    ans += S.size() * (S.size() - 1) / 2;
    for (auto [k, v] : mp) {
        ans -= v * (v - 1) / 2;
    }
    cout << ans << endl;
}
