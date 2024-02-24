#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<char> mp(26);
    rep(i, 26) mp[i] = 'a' + i;
    rep(Q) {
        char c, d;
        cin >> c >> d;
        rep(i, 26) {
            if (mp[i] == c) mp[i] = d;
        }
    }
    for (char &c : S) {
        c = mp[c - 'a'];
    }
    cout << S << endl;
}
