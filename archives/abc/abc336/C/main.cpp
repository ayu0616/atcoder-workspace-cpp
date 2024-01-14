#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int n[] = {0, 2, 4, 6, 8};

int main() {
    ll N;
    cin >> N;
    N--;
    vi nums;
    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (N) {
        nums.push_back(N % 5);
        N /= 5;
    }
    reverse(all(nums));
    rep(i, nums.size()) { cout << n[nums[i]]; }
    cout << endl;
}
