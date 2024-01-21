#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vi B(N);
    int top = 0;
    rep(i, N) {
        int a;
        cin >> a;
        if (a == -1)
            top = i;
        else {
            a--;
            B[a] = i;
        }
    }
    vi ans;
    while (ans.size() < N) {
        ans.push_back(top + 1);
        top = B[top];
    }
    cout << ans << endl;
}
