#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll Q;
    cin >> Q;
    deque<pair<ll, ll>> dq;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll c, x;
            cin >> c >> x;
            dq.push_back({c, x});
        } else {
            ll k;
            cin >> k;
            ll count = 0, sum = 0;
            while (count < k) {
                auto [c, x] = dq.front();
                if (count + c <= k) {
                    count += c;
                    dq.pop_front();
                    sum += c * x;
                } else {
                    dq.front().first -= k - count;
                    sum += (k - count) * x;
                    count = k;
                }
            }
            cout << sum << endl;
        }
    }
}
