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
    int r_idx = -1, m_idx = -1;
    rep(i, S.size()) {
        char s = S[i];
        if (s == 'R') r_idx = i;
        if (s == 'M') m_idx = i;
    }
    if (r_idx > m_idx) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
