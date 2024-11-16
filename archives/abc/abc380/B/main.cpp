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
    string S;
    cin >> S;
    vi A;
    rep(i, S.size() - 1) {
        char s = S[i];
        if (s == '|') {
            A.push_back(0);
        } else {
            A.back()++;
        }
    }
    cout << A << endl;
}
