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
    ll up_cnt = 0, low_cnt = 0;
    for (char c : S) {
        if (isupper(c)) {
            up_cnt++;
        } else {
            low_cnt++;
        }
    }
    if (up_cnt > low_cnt) {
        for(char& c : S) {
            c = toupper(c);
        }
    } else {
        for(char& c : S) {
            c = tolower(c);
        }
    }
    cout << S << endl;
}
