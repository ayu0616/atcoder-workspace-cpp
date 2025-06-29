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
    string S, T;
    cin >> S >> T;
    set<char> ts;
    for (char t : T) {
        ts.insert(t);
    }
    rep(i, 1, S.size()) {
        if ('A' <= S[i] && S[i] <= 'Z') {
            if (ts.find(S[i - 1]) == ts.end()) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
