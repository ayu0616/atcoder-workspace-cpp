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
    string S;
    cin >> N >> S;
    vl v(N);
    rep(i, N) { v[i] = (S[i] - '0') * (i + 1); }
    vl vsum(N);
    vsum[0] = v[0];
    rep(i, N - 1) { vsum[i + 1] = vsum[i] + v[i + 1]; }
    vl ans(10 * N);
    rep(i, N) { ans[i] += 1; }
    rep(i, N) { ans[i] *= vsum[N - 1 - i]; }
    rep(i, N * 10 - 1) {
        ll val = ans[i];
        ans[i] = val % 10;
        ans[i + 1] += val / 10;
    }
    string ans_str = "";
    rep(i, 10 * N) { ans_str += to_string(ans[i]); }
    while (ans_str.size() > 1 && ans_str.back() == '0') {
        ans_str.pop_back();
    }
    reverse(all(ans_str));
    cout << ans_str << endl;
}
