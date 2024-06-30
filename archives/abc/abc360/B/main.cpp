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
    string S, T;
    cin >> S >> T;
    rep(w, 1, S.size()) {
        vs v;
        rep(i, S.size() / w) { v.push_back(S.substr(i * w, w)); }
        v.push_back(S.substr((S.size() / w) * w));
        rep(c, 1, w + 1) {
            string t = "";
            for (auto s : v) {
                if (s.size() >= c) {
                    t += s[c - 1];
                }
            }
            if (t == T) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
