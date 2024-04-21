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
    int N;
    cin >> N;
    vi A(N);
    cin >> A;
    rep(i, N) A[i]--;
    map<int, int> idx;
    rep(i, N) idx[A[i]] = i;
    vpii ans;
    rep(i, N) {
        if (idx[i] == i) continue;
        int j = idx[i];
        idx[A[i]] = j;
        idx[i] = i;
        swap(A[i], A[j]);
        ans.emplace_back(i + 1, j + 1);
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p << endl;
    }
}
