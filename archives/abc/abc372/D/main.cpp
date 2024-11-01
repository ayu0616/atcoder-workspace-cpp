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
    vi H(N);
    cin >> H;
    reverse(all(H));
    multiset<int> seen;
    vi a;
    for (int h : H) {
        auto it = seen.upper_bound(h);
        int ans = distance(it, seen.end());
        a.push_back(ans);
        seen.insert(h);
    }
    reverse(all(a));
    cout << a << endl;
}
