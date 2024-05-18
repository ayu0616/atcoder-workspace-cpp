#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll S(ll i, ll j) {
    ll i_ = i / 4 * 4, j_ = j / 2 * 2;
    ll res = i_ * j_;
    res += i_ * (j % 2);
    if (i % 4 >= 1) res += j_ / 2 * 3;
    if (i % 4 >= 2) res += j_ / 2 * 3;
    if (i % 4 >= 3) res += j_ / 2;
    if (j % 2 == 1) {
        if (i % 4 == 1) res += 2;
        if (i % 4 == 2) res += 3;
        if (i % 4 == 3) res += 3;
    }
    return res;
}

int main() {
    cout << fixed << setprecision(18);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    A = A + 1e9, B = B + 1e9, C = C + 1e9, D = D + 1e9;
    ll ans = S(C, D) - S(C, B) - S(A, D) + S(A, B);
    cout << ans << endl;
}
