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
    auto it = S.find("00");
    while(it != string::npos) {
        S.replace(it, 2, "x");
        it = S.find("00");
    }
    cout<<S.size()<<endl;
}
