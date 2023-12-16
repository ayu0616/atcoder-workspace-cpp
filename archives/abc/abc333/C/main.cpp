#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr ll num[] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111, 11111111111, 111111111111};

int main() {
    int N;
    cin >> N;
    vector<ll> sum;
    rep(i, 12) rep(j, 12) rep(k, 12) {
        if (find(all(sum), num[i] + num[j] + num[k]) == sum.end()) sum.push_back(num[i] + num[j] + num[k]);
    }
    sort(all(sum));
    cout << *(sum.begin() + (N-1)) << endl;
}
