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
    ll Q;
    cin >> Q;
    vl snakes;
    ll sub = 0;
    ll sub_cnt = 0;
    ll last = 0;
    deque<int> q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll l;
            cin >> l;
            if (snakes.empty()) {
                snakes.push_back(0);
            } else {
                snakes.push_back(snakes.back() + last);
            }
            q.push_back(l);
            last = l;
        } else if (type == 2) {
            sub += q.front();
            q.pop_front();
            sub_cnt++;
        } else {
            ll k;
            cin >> k;
            k += sub_cnt;
            cout << snakes[k - 1] - sub << endl;
        }
    }
}
