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
    vs S(N);
    cin >> S;
    rep(i, N - 2) {
        if (S[i] == "sweet" && S[i + 1] == "sweet") {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
