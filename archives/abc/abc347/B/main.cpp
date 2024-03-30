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
    set<string> st;
    rep(i, 1, S.size() + 1) {
        rep(j, 0, S.size() - i + 1) { st.insert(S.substr(j, i)); }
    }
    cout << st.size() << endl;
}
