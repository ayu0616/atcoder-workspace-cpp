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
    ll a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    bool ok = false;

    for (ll x : {a, d})
        for (ll y : {b, e})
            for (ll z : {c, f})
                if ((g < x && x < j) && (h < y && y < k) && (i < z && z < l)) {
                    ok = true;
                }
    swap(a, g);
    swap(b, h);
    swap(c, i);
    swap(d, j);
    swap(e, k);
    swap(f, l);
    for (ll x : {a, d})
        for (ll y : {b, e})
            for (ll z : {c, f})
                if ((g < x && x < j) && (h < y && y < k) && (i < z && z < l)) {
                    ok = true;
                }
    ok |= a == g && b == h && c == i && d == j && e == k && f == l;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
