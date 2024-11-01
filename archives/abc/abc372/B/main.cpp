#include <cassert>
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
    ll M;
    cin >> M;
    ll M2 = M;
    vi A;
    while (M) {
        A.push_back(M % 3);
        M /= 3;
    }
    int N = A.size();
    assert(N <= 20);
    vi ans;
    rep(i, N) {
        int a = A[i];
        rep(j, a) ans.push_back(i);
    }
    int s = 0;
    for (int a : ans) s += pow(3, a);
    assert(s == M2);
    cout << ans.size() << endl;
    cout << ans << endl;
}
