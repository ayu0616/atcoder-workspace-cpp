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
        vector<ll> A(N);
        cin >> A;

        map<ll, ll> count;
        rep(i, N) { count[A[i]]++; }

        if (count[A[0]] == N || (min(count[A[0]], count[-A[0]]) == N / 2 && max(count[A[0]], count[-A[0]]) == N / 2 + 1)) {
            cout << "Yes" << endl;
            continue;
        }

        sort(all(A), [&](auto a, auto b) { return abs(a) < abs(b); });
        bool ok = true;
        rep(i, N - 1) {
            if (A[i + 1] * A[0] != A[i] * A[1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
