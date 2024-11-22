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
    if (S.size() % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    map<char, int> mp;
    for (int i = 0; i < S.size(); i += 2) {
        if (S[i] != S[i + 1]) {
            cout << "No" << endl;
            return 0;
        }
        mp[S[i]]+=2;
    }
    for (auto [k, v] : mp) {
        if (v != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
