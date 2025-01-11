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
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    sort(all(A));
    vl A1(A.begin(), A.begin() + N / 2);
    vl A2(A.begin() + N / 2, A.end());
    ll ans = 0;
    while (!A1.empty() && !A2.empty()) {
        ll a1 = A1.back();
        ll a2 = A2.back();
        if (a1 * 2 <= a2) {
            A1.pop_back();
            A2.pop_back();
            ans++;
        } else {
            A1.pop_back();
        }
    }
    if (N % 2 == 1) {
        A1.clear();
        A2.clear();
        A1 = vl(A.begin(), A.begin() + N / 2 + 1);
        A2 = vl(A.begin() + N / 2 + 1, A.end());
        ll ans2 = 0;
        while (!A1.empty() && !A2.empty()) {
            ll a1 = A1.back();
            ll a2 = A2.back();
            if (a1 * 2 <= a2) {
                A1.pop_back();
                A2.pop_back();
                ans2++;
            } else {
                A1.pop_back();
            }
        }
        chmax(ans, ans2);
    }
    cout << ans << endl;
}
