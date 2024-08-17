#include <iostream>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N, K;
vi R;
vvi ans;
vi tmp;

void solve(int depth) {
    if (depth == N) {
        if (accumulate(all(tmp), 0) % K == 0) {
            ans.push_back(tmp);
        }
        return;
    }
    for (int i = 1; i <= R[depth]; i++) {
        tmp[depth] = i;
        solve(depth + 1);
    }
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> K;
    R.resize(N);
    cin >> R;
    tmp.resize(N);
    solve(0);
    cout << ans << endl;
}
