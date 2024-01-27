#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Count {
    int value = 0;
    map<int, int> mp;

    void add(int n) {
        mp[n]++;
        if (mp[n] == 1) value++;
    }

    void erase(int n) {
        mp[n]--;
        if (mp[n] == 0) value--;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vi a(N);
    cin >> a;

    Count cnt;
    int l = 0, r = 0;
    int ans = 0;
    while (true) {
        cnt.add(a[r]);
        while (cnt.value > K) {
            l++;
            cnt.erase(a[l - 1]);
        }
        chmax(ans, r - l + 1);
        if (r == N - 1) break;
        r++;
    }
    cout << ans << endl;
}
