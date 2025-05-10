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
    queue<ll> que;
    rep(Q) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            que.push(x);
        } else {
            if (que.empty()) {
                cout << -1 << endl;
            } else {
                cout << que.front() << endl;
                que.pop();
            }
        }
    }
}
