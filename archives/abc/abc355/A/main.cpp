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
    ll A,B;
    cin >> A >> B;
    if (A == B) {
        cout << -1 << endl;
        return 0;
    }
    set<ll> s;
    s.insert(A);
    s.insert(B);
    rep(i, 1, 4) {
        if (s.find(i) == s.end()) {
            cout << i << endl;
            return 0;
        }
    }
}
