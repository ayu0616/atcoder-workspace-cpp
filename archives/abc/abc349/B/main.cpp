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
    map<char, int> mp;
    rep(i, S.size()) { mp[S[i]]++; }
    map<int, int> mp2;
    for (auto [k, v] : mp) {
        mp2[v]++;
    }
    bool ok = true;
    for (auto [k, v] : mp2) {
        if (v != 0 && v != 2) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}
