#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

int N;

ll question(ll i, ll j) {
    cout << "? " << i << " " << j << endl;
    ll res;
    cin >> res;
    return res;
}

void answer(ll x) { cout << "! " << x << endl; }

ll solve(ll l, ll r) {
    if (l == r) return 0;
    ll res = 0;
    ll i = -1, j = -1;
    for (i = N; i >= 0; i--) {
        ll m = (1LL << i);
        ll r_m = r / m;
        if (r_m <= 0) continue;
        if((r_m-1)*m<l) continue;
        j = r_m - 1;
        break;
    }
    ll m = (1LL << i);
    res += question(i, j);
    res += solve(l, m * j);
    res += solve(m * (j + 1), r);
    return res % 100;
}

int main() {
    cout << fixed << setprecision(18);
    ll L, R;
    cin >> N >> L >> R;
    ll ans = solve(L, R + 1);
    answer(ans);
}
