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
    int cur = S.find('A');
    int ans = 0;
    for (char c = 'B'; c <= 'Z'; c++) {
        int next = S.find(c);
        if (next == string::npos) {
            break;
        }
        ans += abs(next - cur);
        cur = next;
    }
    cout << ans << endl;
}
