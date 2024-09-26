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
    for (auto &a : A) a--;

    vb a_exists(N);
    for (auto a : A) a_exists[a] = true;

    vvpll sections(N);
    rep(i, N) { sections[i].emplace_back(0, -1); }
    rep(i, N) {
        ll a = A[i];
        if (sections[a].back().second == -1) {
            sections[a].back().second = i;
            sections[a].emplace_back(i + 1, -1);
        }
    }
    rep(i, N) {
        if (sections[i].back().second == -1) {
            sections[i].back().second = N;
        }
    }
    ll ans = 0;
    rep(i, N) {
        if (!a_exists[i]) continue;
        auto &secs = sections[i];
        for (auto &[l, r] : secs) {
            int n = r - l;
            ans += n * (n + 1) / 2;
        }
    }
    cout << ans << endl;
}
