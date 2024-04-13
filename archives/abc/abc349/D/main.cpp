#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

pll div(ll n) {
    ll k = 0;
    while (n % 2 == 0) {
        n /= 2;
        k++;
    }
    return {k, n};
}

int main() {
    cout << fixed << setprecision(18);
    ll L, R;
    cin >> L >> R;
    vpll ans;
    if (L == 0) {
        ll k = 0;
        while((1LL << (k+1)) <= R) k++;
        ans.emplace_back(0, 1LL << k);
        L = 1LL << k;
    }
    ll l = L, r = l;
    while (r < R) {
        auto [k, n] = div(l);
        // debug(l);
        // debug(k);
        // debug(n);
        r = (1LL << k) * (n + 1);
        while (r > R) {
            k--;
            n <<= 1;
            r = (1LL << k) * (n + 1);
        }
        ans.emplace_back(l, r);
        l = r;
    }
    cout << ans.size() << endl;
    for (auto [l, r] : ans) {
        cout << l << " " << r << endl;
    }
}
