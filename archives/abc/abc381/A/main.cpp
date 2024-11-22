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
    string S;
    cin >> N >> S;
    if (N % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    int half = N / 2;
    rep(i, N) {
        if (i < half) {
            if (S[i] != '1') {
                cout << "No" << endl;
                return 0;
            }
        } else if (i == half) {
            if (S[i] != '/') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (S[i] != '2') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
