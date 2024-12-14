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
    char c1, c2;
    string S;
    cin >> N >> c1 >> c2 >> S;
    for (auto &c : S) {
        if (c != c1) {
            c = c2;
        }
    }
    cout << S << endl;
}
