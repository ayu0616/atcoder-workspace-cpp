#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl p = hassaku::prime_factorize(N);
    map<ll, ll> mp;
    for (auto x : p) {
        mp[x]++;
    }
    vl puniq;
    for (auto [k, v] : mp) {
        puniq.push_back(k);
    }
    auto solve = [&](auto f, int idx = 0, ll a = 1) {
        if (idx == puniq.size()) {
            ll b = N / a;
            ll D = -3 * a * a + 12 * b;
            if (D < 0) return false;
            ll x1 = (3 * a + sqrt(D)) / 6;
            ll y1 = x1 - a;
            if (x1 > 0 && y1 > 0 && x1 * x1 * x1 - y1 * y1 * y1 == N) {
                cout << x1 << " " << y1 << endl;
                return true;
            }
            x1++;
            y1 = x1 - a;
            if (x1 > 0 && y1 > 0 && x1 * x1 * x1 - y1 * y1 * y1 == N) {
                cout << x1 << " " << y1 << endl;
                return true;
            }
            ll x2 = (3 * a - sqrt(D)) / 6;
            ll y2 = x2 - a;
            if (x2 > 0 && y2 > 0 && x2 * x2 * x2 - y2 * y2 * y2 == N) {
                cout << x2 << " " << y2 << endl;
                return true;
            }
            x2++;
            y2 = x2 - a;
            if (x2 > 0 && y2 > 0 && x2 * x2 * x2 - y2 * y2 * y2 == N) {
                cout << x2 << " " << y2 << endl;
                return true;
            }
            return false;
        } else {
            bool res = false;
            for (int i = 0; i <= mp[puniq[idx]]; i++) {
                res |= f(f, idx + 1, a);
                a *= puniq[idx];
            }
            return res;
        }
    };
    bool ok = solve(solve);
    if (!ok) {
        cout << -1 << endl;
    }
}
