#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;
ll N, M;
vvl ans;

void solve(vl& v) {
    if (!v.empty() && v.back() > M) return;
    if (!v.empty() && 10 * (N - v.size()) + v.back() > M) return;
    if (v.size() == N) {
        ans.push_back(v);
        return;
    }
    int ai = 1;
    if (v.empty()) {
        ai = 1;
    } else {
        ai = v.back() + 10;
    }
    while (ai <= M) {
        v.push_back(ai);
        solve(v);
        v.pop_back();
        ai++;
    }
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> M;
    vl v;
    solve(v);
    sort(all(ans));
    cout << ans.size() << endl;
    cout << ans << endl;
}
