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
    string S;
    cin >> S;
    reverse(all(S));
    ll sum = 0;
    rep(i, S.size()) {
        int s = S[i] - '0';
        int t = (sum % 10);
        int diff = (10 + s - t) % 10;
        sum += diff;
    }
    cout << sum + S.size() << endl;
}
