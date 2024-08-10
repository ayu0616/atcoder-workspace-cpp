#include <set>
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
    set<int> s;
    multiset<int> ms;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            s.insert(x);
            ms.insert(x);
        } else if (t == 2) {
            int x;
            cin >> x;
            ms.erase(ms.find(x));
            if (!ms.count(x)) {
                s.erase(x);
            }
        } else {
            cout << s.size() << endl;
        }
    }
}
