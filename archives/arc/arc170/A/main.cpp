#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    string S, T, s_sub, t_sub;
    cin >> N >> S >> T;
    rep(i, N) {
        if (S[i] != T[i]) {
            s_sub += S[i];
            t_sub += T[i];
        }
    }
    int M = s_sub.size();
    int cur = 0;
    rep(i, M) {
        if (s_sub[i] == 'A')
            cur--;
        else
            cur++;
        if (cur < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (cur >= 0)
        cout << (M - cur) / 2 + cur << endl;
    else
        cout << -1 << endl;
}
