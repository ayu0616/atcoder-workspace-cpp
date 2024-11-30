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
    ll N, D;
    string S;
    cin >> N >> D >> S;
    rep(i, N) {
        int j = N - i - 1;
        if (S[j] == '@' && D > 0) {
            S[j] = '.';
            D--;
        }
    }
    cout << S << endl;
}
