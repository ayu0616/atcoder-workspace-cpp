#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll T;
    cin >> T;
    rep(T) {
        ll N;
        cin >> N;
        vl S(N);
        cin >> S;
        ll first = S[0], last = S[N - 1];
        vl s;
        rep(i, 1, N - 1) { s.push_back(S[i]); }
        sort(all(s));
        ll cur = first;
        ll ans = 2;
        while (cur * 2 < last) {
            auto it = upper_bound(all(s), cur * 2);
            if (it == s.begin()) {
                ans = -1;
                break;
            }
            it--;
            if (*it == cur) {
                ans = -1;
                break;
            }
            cur = *it;
            ans++;
        }
        cout << ans << endl;
    }
}
