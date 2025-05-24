#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

map<int, mint> memo;
mint fact(int n) {
    if (n == 0) return 1;
    if (memo.count(n)) return memo[n];
    mint res = n;
    res *= fact(n - 1);
    memo[n] = res;
    return res;
}

int main() {
    cout << fixed << setprecision(18);
    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vi bins;
        while (N > 0) {
            bins.push_back(N % 2);
            N /= 2;
        }
        int L = bins.size();
        mint ans = 0;
        mint s = 0;
        int cnt = 0;
        for (int i = L - 1; i >= 0; i--) {
            if (bins[i] == 1) {
                s += mint(2).pow(i);
                cnt++;
            }
            int k = K - cnt;
            int n = i;
            if (k > 0 && n >= k) {
                mint t = s + mint(2).pow(n) - 1;
                ans += (fact(n) / (fact(k) * fact(n - k))) * k / n * t;
            }
        }
        cout << ans << endl;
    }
}
