#include <string>
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
    set<string> valid;
    rep(i, 1, 350) {
        string s = "ABC";
        string num = "00" + to_string(i);
        num = num.substr(num.size() - 3);
        s += num;
        valid.insert(s);
    }
    valid.erase("ABC316");
    if (valid.count(S)) {
        cout << ("Yes") << endl;
    } else {
        cout << ("No") << endl;
    }
}
