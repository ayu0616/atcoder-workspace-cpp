#include <atcoder/all>

#include "../../lib.hpp"

using namespace atcoder;

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll n;
    cin >> n;
    constexpr char bracket[] = {'(', ')'};
    rep(i, 1LL << n) {
        string s;
        rep(j, n) {
            if (i >> j & 1) {
                s += bracket[1];
            } else {
                s += bracket[0];
            }
        }
        reverse(all(s));
        stack<char> st;
        bool ok = true;
        rep(j, n) {
            if (s[j] == bracket[0]) {
                st.push(s[j]);
            } else {
                if (st.empty()) {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }
        if (ok && st.empty()) {
            cout << s << endl;
        }
    }
}
