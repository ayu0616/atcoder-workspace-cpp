#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N, T;
    cin >> N >> T;
    vi A(T);
    vl B(T);
    rep(i, T) {
        cin >> A[i] >> B[i];
    }
    vl scores(N, 0);
    map<ll, int> mp;
    mp[0] = N;
    rep(i, T) {
        mp[scores[A[i] - 1]]--;
        if (mp[scores[A[i] - 1]] == 0) {
            mp.erase(scores[A[i] - 1]);
        }
        scores[A[i] - 1] += B[i];
        mp[scores[A[i] - 1]]++;
        cout << mp.size() << endl;
    }
}
