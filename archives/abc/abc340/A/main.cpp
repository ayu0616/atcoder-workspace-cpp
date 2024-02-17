#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int A, B, D;
    cin >> A >> B >> D;
    vi ans;
    for (int i = A; i <=B; i +=D) {
        ans.push_back(i);
    }
    cout << fixed << setprecision(18);
    cout << ans << endl;
}
