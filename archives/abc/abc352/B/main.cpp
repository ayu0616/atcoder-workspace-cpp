#include <queue>
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
    string S, T;
    cin >> S >> T;
    int i = 0;
    vi ans;
    for (auto s : S) {
        while (T[i] != s) {
            i++;
        }
        ans.push_back(i + 1);
        i++;
    }
    cout << ans << endl;
}
