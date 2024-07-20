#include <cassert>
#include <numeric>
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
    vl v(35);
    v[0] = 10, v[1] = 9;
    rep(i, 2, 35) {
        int k = i / 2;
        v[i] = 9 * powl(10, k);
    }
    vl v_sum(36);
    rep(i, 35) { v_sum[i + 1] = accumulate(v.begin(), v.begin() + i + 1, 0LL); }
    int dig = lower_bound(all(v_sum), N) - v_sum.begin();
    vi ans(dig);
    ll cur = v_sum[dig - 1] + 1;
    rep(i, (dig + 1) / 2) {
        ll b, n;
        if ((i == 0 && dig >= 2)) {
            b = v[dig - 2 * i - 1] / 9;
            n = 1;
        } else if (dig % 2 == 0 && i == dig / 2 - 1) {
            b = 1;
            n = 0;
        } else {
            b = powl(10, (ll)((dig - 2 * i + 1) / 2)) / 10;
            n = 0;
        }
        while (n < 10) {
            if (cur + b > N) {
                break;
            }
            cur += b;
            n++;
        }
        assert(n < 10);
        ans[i] = n;
        ans[dig - i - 1] = n;
    }
    string s;
    for (auto a : ans) {
        s += to_string(a);
    }
    cout << s << endl;
}
