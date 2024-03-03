#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    ll ans = 1;
    for (ll i = 1; i * i * i <= N; i++) {
        string s = to_string(i * i * i);
        string t = s;
        reverse(all(t));
        if (s == t) {
            ans = i * i * i;
        }
    }
    cout << ans << endl;
}
