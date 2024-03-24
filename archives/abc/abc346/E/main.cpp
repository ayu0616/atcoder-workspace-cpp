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
    ll H, W, M;
    cin >> H >> W >> M;
    vl T(M), A(M), X(M);
    rep(i, M) { cin >> T[i] >> A[i] >> X[i]; }
    map<pll, pll> mp;
    // rep(i, H) mp[{0, i}] = {0, 0};
    // rep(i, W) mp[{1, i}] = {0, 0};
    rep(i, M) {
        ll t = T[i], a = A[i], x = X[i];
        a--;
        mp[pll(t, a)] = pll(i + 1, x);
    }

    vector<tuple<ll, ll, ll, ll>> vec;
    for (auto [k, v] : mp) {
        vec.push_back({v.first, k.first, k.second, v.second});
    }
    sort(all(vec));
    reverse(all(vec));
    ll row_cnt = 0, col_cnt = 0;
    map<ll, ll> col;
    for (auto [i, t, a, x] : vec) {
        // cerr<<i<<" "<<t<<" "<<a<<" "<<x<<endl;
        if (t == 1) {
            col[x] += W - col_cnt;
            row_cnt++;
        } else {
            col[x] += H - row_cnt;
            col_cnt++;
        }
    }
    ll s = 0;
    for (auto [k, v] : col) {
        s += v;
    }
    col[0] += H * W - s;
    ll cnt = 0;

    rep(i, 200000 + 1) {
        if (col[i]) {
            cnt++;
        }
    }
    cout << cnt << endl;
    rep(i, 200000 + 1) {
        if (col[i]) {
            cout << i << " " << col[i] << endl;
        }
    }
}
